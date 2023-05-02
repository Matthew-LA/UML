package com.example.db3;

import androidx.appcompat.app.AppCompatActivity;

import android.app.AlertDialog;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.toolbox.Volley;

import org.json.JSONException;
import org.json.JSONObject;

public class UpdateUser extends AppCompatActivity {

    EditText emailEditText, nameEditText, passwordEditText, phoneEditText;
    Button updateButton;
    int userId;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_update_user);

        emailEditText = findViewById(R.id.update_email);
        passwordEditText = findViewById(R.id.update_password);
        nameEditText = findViewById(R.id.update_name);
        phoneEditText = findViewById(R.id.update_phone);
        updateButton = findViewById(R.id.update_button);

        Intent intent = getIntent();
        userId = intent.getIntExtra("userId", -1);

        fetchUserDetails(userId);

        updateButton.setOnClickListener(view -> {
            String email = emailEditText.getText().toString();
            String name = nameEditText.getText().toString();
            String password = passwordEditText.getText().toString();
            String phone = phoneEditText.getText().toString();

            Response.Listener<String> responseListener = response -> {
                try {
                    JSONObject jsonResponse = new JSONObject(response);
                    boolean success = jsonResponse.getBoolean("success");

                    if (success) {
                        Intent intent1 = new Intent(UpdateUser.this, Dashboard.class);
                        UpdateUser.this.startActivity(intent1);

                    } else {
                        AlertDialog.Builder builder = new AlertDialog.Builder(UpdateUser.this);
                        builder.setMessage("User Update Failed").setNegativeButton("Retry", null).create().show();
                    }
                } catch (JSONException e) {
                    e.printStackTrace();
                }
            };

            QueryRequest queryRequest = new QueryRequest.Builder(getString(R.string.url) + "update_user.php", responseListener)
                    .userId(userId)
                    .email(email)
                    .password(password)
                    .name(name)
                    .phone(phone)
                    .build();
            RequestQueue queue = Volley.newRequestQueue(UpdateUser.this);
            queue.add(queryRequest);
        });
    }
    private void fetchUserDetails(int userId) {
        Response.Listener<String> responseListener = response -> {
            try {
                JSONObject jsonResponse = new JSONObject(response);
                boolean success = jsonResponse.getBoolean("success");

                if (success) {
                    String email = jsonResponse.getString("email");
                    String name = jsonResponse.getString("name");
                    String password = jsonResponse.getString("password");
                    String phone = jsonResponse.getString("phone");

                    emailEditText.setText(email);
                    nameEditText.setText(name);
                    passwordEditText.setText(password);
                    phoneEditText.setText(phone);

                } else {
                    Toast.makeText(UpdateUser.this, "Failed to fetch user details", Toast.LENGTH_SHORT).show();
                }
            } catch (JSONException e) {
                e.printStackTrace();
            }
        };

        QueryRequest queryRequest = new QueryRequest.Builder(getString(R.string.url) + "get_user_details.php", responseListener)
                .userId(userId)
                .build();
        RequestQueue queue = Volley.newRequestQueue(UpdateUser.this);
        queue.add(queryRequest);
    }

}
