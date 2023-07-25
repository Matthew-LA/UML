/**********************************************************************
 *  Linear Feedback Shift Register (part B) ps1b-readme.txt template
 **********************************************************************/

Name: Matthew Lorette Anaya

Hours to complete assignment: 3
/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
This assignment aims to encode an image using a Linear Feedback Shift Register (Fibonacci).
 It XORs each pixel with a newly generated LSFR value.

 This encodes the image -> and this image is unique to the seed that was used to encode it, that is, if a new seed is given for the same input image,
 the output image will change.

 To decode an encoded image, the initial seed is needed. This seed has to be same seed that was used to encode the image.
 XORing each pixel value of the encoded image with bits generated from the same seed would reverse the encoding and 'decodes' 
 the image back to the original image.

/**********************************************************************
 *  If you did any implementation for extra credit, describe it
 *  here and why it is interesting.
 **********************************************************************/




/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
I continued to get an error using the -Wall -Werror on compiling FibLFSR.cpp
stating "error: ‘to_string’ is not a member of ‘std’; did you mean ‘wstring’?"
Im assuming it has something to do with using that line it uses and earlier ofrm of C++ to compile the code. everything compiled fine once I removed those flags off FibLFSR object in the Makefile. Still not sure why it does that.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
