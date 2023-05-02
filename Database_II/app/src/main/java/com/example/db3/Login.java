package com.example.db3;

import android.app.AlertDialog;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import androidx.appcompat.app.AppCompatActivity;

import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.toolbox.Volley;

import org.json.JSONException;
import org.json.JSONObject;

public class Login extends AppCompatActivity {

    EditText emailEditText, passwordEditText;
    Button loginButton;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);

        emailEditText = findViewById(R.id.email);
        passwordEditText = findViewById(R.id.password);
        loginButton = findViewById(R.id.login_button);

        loginButton.setOnClickListener(view -> {
            String email = emailEditText.getText().toString();
            String password = passwordEditText.getText().toString();

            Response.Listener<String> responseListener = response -> {
                try {
                    JSONObject jsonResponse = new JSONObject(response);
                    boolean success = jsonResponse.getBoolean("success");

                    if (success) {
                        int id = jsonResponse.getInt("id");
                        String role = jsonResponse.getString("role");

                        UserSession userSession = (UserSession) getApplicationContext();
                        userSession.setUserId(id);
                        userSession.setRole(role);
                        if (role.equals("parent")) {
                            int childId = jsonResponse.getInt("childId");
                            userSession.setChildId(childId);
                        }
                        if (role.equals("student")) {
                            int grade = jsonResponse.getInt("grade");
                            userSession.setGrade(grade);
                        }

                        Log.d("please", "Email: " + email + " role: " + role);

                        Intent intent = new Intent(Login.this, Dashboard.class);
                        Login.this.startActivity(intent);
                    } else {
                        AlertDialog.Builder builder = new AlertDialog.Builder(Login.this);
                        builder.setMessage("Login Failed").setNegativeButton("Retry", null).create().show();
                    }
                } catch (JSONException e) {
                    e.printStackTrace();
                }
            };

            String url = getString(R.string.url) + "login.php";
            Log.d("please", "URL: " + url);
            QueryRequest queryRequest = new QueryRequest.Builder(getString(R.string.url) + "login.php", responseListener)
                    .email(email)
                    .password(password)
                    .build();
            RequestQueue queue = Volley.newRequestQueue(Login.this);
            queue.add(queryRequest);
        });
    }
}

