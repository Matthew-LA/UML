import json
import time
import socket
import os
import multiprocessing
from secure_drop_model import *
from Crypto.Hash import SHA256

# default udp socket implementation
# SO_REUSEADDR(linux kernel<3.9)- allows the same port and ip address to be used to send even
#                                 if in use by mutliple users
# SHA used to encode/decode email for encryption/security purposes of packets sent/received
# .encode/decode() used to turn packets into strings as they are sent/recieved(.recvfrom())
# as a tuple of pairs (bytes, address) in python3
def UDP_server (message: str, public_key: str):
    try:
        # Create a socket that constantly broadcasts the json object
        # created below
        udp_sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM, socket.IPPROTO_UDP)
        udp_sock.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
        udp_sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        
        # Create another socket to find the local ip and use as an
        # identifier as to whom the packet sender is
        s_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        s_sock.connect(("8.8.8.8", 80))
        packet_sender = s_sock.getsockname()[0]
        
        # Hash the email and encode it to send in packet
        sha_256 = SHA256.new()
        sha_256.update(message.encode())
        h_email = str(sha_256.hexdigest())
        
        # Define the port to send UDP packets to
        udp_port = 9999
        
        is_sending = True
        
        while (is_sending):
            # Create the JSON object and broadcast
            udp_pack = json.dumps({"Email": h_email, "IP": packet_sender, "public_key": public_key }).encode()
            try:
                bytes_sent = udp_sock.sendto(udp_pack, ('<broadcast>', udp_port))
                if bytes_sent > 0:
                    pass
                 #   print("Info sent successfully")
            except Exception as e:
                print("Error occurred while sending data:", e)
            time.sleep(.1)

    except:
        print("failed to send")
        pass
    finally:
        udp_sock.close()
        
   
        
def UDP_client (user: User, process_q: multiprocessing.Queue):
    port = 9999
    ip = ""
    listening_address = (ip, port)
    
    try:
        print("Receving data")
        # Same as send function except this socket is for the recieving end
        udp_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_UDP)
        udp_sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        udp_sock.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
        udp_sock.bind(listening_address)
        
        # Create another socket to find the local ip and use as an
        # identifier as to whom the packet sender is
        r_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        r_sock.connect(("8.8.8.8", 80))
        from_me = r_sock.getsockname()[0]
        
        # Set a timeout of 5 seconds, start it and
        # keep track of whether we have timed out
        udp_sock.settimeout(5)
        start_time = time.time()
        timed_out = False

        while (not timed_out):
            try:
                # Attempt to receive data from the socket
                info, address = udp_sock.recvfrom(1024)
            except socket.timeout:
                # If a timeout occurs, set the timed_out flag to True
                # to break out of the loop
                timed_out = True
            except socket.error as e:
                print("Error receiving data:", e)
                break
                
            if time.time() - start_time > udp_sock.gettimeout():
                # If the timeout has been exceeded, set the timed_out flag
                # to True to break out of the loop
                timed_out = True
            else:
                # If the timeout has not been exceeded, continue processing
                # the received data
                
                # The packet is from this machines/user's ip
                if json.loads(info.decode())["IP"] == from_me:
                    pass

                # The packet is from a contact that is already on the list
                elif user.contact_ping_list.__contains__(json.loads(info.decode())):
                    pass
                
                # Otherwise it is from a unique online contact and append to the user.contact_ping_list
                else:
                    try:
                        user.contact_ping_list.append(json.loads(info.decode()))
                    except:
                        pass
    
        
    except:
        pass
    finally:
        udp_sock.close()
        process_q.put(user)
        
        
def tcp_client(contact_info: dict, file_info: dict):
    port = 9998
    host = contact_info["IP"]
    connection = (host, port)
    file_info_json = json.dumps(file_info)
    file_data = ""
    file_location = str(file_info["file_location"])
    path = os.path.expanduser(file_location)
    
    try:
        tcp_sock = socket.socket()
        tcp_sock.connect(connection)
        tcp_sock.send(file_info_json.encode())
        tcp_sock.recv(4096)
        
        with open(path, "r+") as file_to_send:
            while True:
                file_data = file_to_send.readline()
                if not file_data:
                    break
                tcp_sock.send(file_data.encode())
            print("File has been sent")
    finally:
        tcp_sock.close()
    

def tcp_server():
    port = 9998
    sock_bind = ("", port)
    
    tcp_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    tcp_sock.setsockopt(socket.SOL_SOCKET,  socket.SO_REUSEADDR, 1)
    tcp_sock.bind(sock_bind)
    tcp_sock.listen(5)
    
    try:
        
        while True:
            client, address = tcp_sock.accept()
            client_info = json.loads(client.recv(1024).decode())
            print("\nContact '" + client_info["name"] + " <" + client_info["email"] + ">' is sending a file.")
            
                
            with open(client_info["file_name"], "w+") as received_file:
                while True:
                    sent_file = client.recv(4096).decode()
                    if not sent_file:
                        break
                    received_file.write(sent_file)
                client.send("File has been successfully transferred.".encode())
                client.close()
               
                
    except socket.error as e:
        print("Error receiving file:", e)
        pass
        
    finally:
        tcp_sock.close()
            
