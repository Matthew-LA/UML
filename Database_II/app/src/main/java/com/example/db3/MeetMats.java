package com.example.db3;

import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;
import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.toolbox.Volley;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

public class MeetMats extends AppCompatActivity {
    private int userId;
    private LinearLayout meetMatsLayout;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_meet_mats);

        Intent intent = getIntent();
        userId = intent.getIntExtra("userId", -1);

        meetMatsLayout = findViewById(R.id.meetMatsLayout);

        fetchMeetMats();

        Button homeButton = findViewById(R.id.homeButton);
        homeButton.setOnClickListener(view -> {
            Intent intent1 = new Intent(MeetMats.this, Dashboard.class);
            startActivity(intent1);
        });
    }

    private void fetchMeetMats() {
        Response.Listener<String> responseListener = response -> {
            try {
                JSONObject jsonResponse = new JSONObject(response);
                boolean success = jsonResponse.getBoolean("success");

                if (success) {
                    JSONArray meetMats = jsonResponse.getJSONArray("meet_mats");
                    createMeetMatsList(meetMats);
                } else {
                    Toast.makeText(MeetMats.this, "Failed to fetch meet mats", Toast.LENGTH_SHORT).show();
                }
            } catch (JSONException e) {
                e.printStackTrace();
            }
        };

        QueryRequest queryRequest = new QueryRequest.Builder(getString(R.string.url) + "get_meet_mats.php", responseListener)
                .userId(userId)
                .build();
        RequestQueue queue = Volley.newRequestQueue(MeetMats.this);
        queue.add(queryRequest);
    }

    private void createMeetMatsList(JSONArray meetMats) throws JSONException {
        for (int i = 0; i < meetMats.length(); i++) {
            JSONObject mat = meetMats.getJSONObject(i);
            String meetingName = mat.getString("meeting_name");
            String groupName = mat.getString("group_name");
            String title = mat.getString("title");
            String author = mat.getString("author");
            String type = mat.getString("type");
            String url = mat.getString("url");
            String notes = mat.getString("notes");
            String assignedDate = mat.getString("assigned_date");

            TextView matTextView = new TextView(this);
            String matText = "Meeting Name: " + meetingName + "\n" +
                    "Group name: " + groupName + "\n" +
                    "Title: " + title + "\n" +
                    "Author: " + author + "\n" +
                    "Type: " + type + "\n" +
                    "URL: " + url + "\n" +
                    "Notes: " + notes + "\n" +
                    "Assigned date: " + assignedDate + "\n";
            matTextView.setText(matText);
            meetMatsLayout.addView(matTextView);
        }
    }
}

