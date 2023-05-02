package com.example.db3;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.Gravity;
import android.view.View;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.toolbox.Volley;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

public class ReadingGroups extends AppCompatActivity {
    private int userId;
    private int grade;
    private LinearLayout groupsLayout;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_reading_groups);

        // Get user info
        Intent intent = getIntent();
        userId = intent.getIntExtra("userId", -1);
        grade = intent.getIntExtra("grade", -1);
        Log.d("please", "id: " + userId + " grade: " + grade);

        groupsLayout = findViewById(R.id.groupsLayout);

        // Fetch reading groups
        fetchReadingGroups();

        // Create the Home button
        Button homeButton = findViewById(R.id.homeButton);
        homeButton.setOnClickListener(view -> {
            Intent intent1 = new Intent(ReadingGroups.this, Dashboard.class);
            startActivity(intent1);
        });
    }

    private void fetchReadingGroups() {
        Response.Listener<String> responseListener = response -> {
            try {
                JSONObject jsonResponse = new JSONObject(response);
                boolean success = jsonResponse.getBoolean("success");

                if (success) {
                    JSONArray groups = jsonResponse.getJSONArray("groups");
                    createReadingGroupList(groups);
                } else {
                    Toast.makeText(ReadingGroups.this, "Failed to fetch reading groups", Toast.LENGTH_SHORT).show();
                }
            } catch (JSONException e) {
                e.printStackTrace();
            }
        };

        QueryRequest queryRequest = new QueryRequest.Builder(getString(R.string.url) + "get_groups.php", responseListener)
                .userId(userId)
                .grade(grade)
                .build();
        RequestQueue queue = Volley.newRequestQueue(ReadingGroups.this);
        queue.add(queryRequest);
    }

    private void createReadingGroupList(JSONArray groups) throws JSONException {
        for (int i = 0; i < groups.length(); i++) {
            JSONObject group = groups.getJSONObject(i);
            int groupId = group.getInt("group_id");
            String groupName = group.getString("name");
            String groupDescription = group.getString("description");
            addButton(groupName, groupDescription, groupId, groupsLayout);
        }
    }

    private void addButton(String groupName, String groupDescription, final int groupId, LinearLayout layout) {
        Button button = new Button(this);
        button.setText(groupName + " - " + groupDescription);
        LinearLayout.LayoutParams buttonLayoutParams = new LinearLayout.LayoutParams(
                LinearLayout.LayoutParams.WRAP_CONTENT, LinearLayout.LayoutParams.WRAP_CONTENT);
        buttonLayoutParams.gravity = Gravity.CENTER_HORIZONTAL;
        button.setLayoutParams(buttonLayoutParams);
        button.setOnClickListener(view -> {
            joinReadingGroup(groupId);
            Intent intent = new Intent(ReadingGroups.this, Dashboard.class);
            startActivity(intent);
        });
        layout.addView(button);
    }

    private void joinReadingGroup(int groupId) {
        Response.Listener<String> responseListener = response -> {
            try {
                JSONObject jsonResponse = new JSONObject(response);
                boolean success = jsonResponse.getBoolean("success");

                if (success) {
                    Toast.makeText(ReadingGroups.this, "Successfully joined the reading group", Toast.LENGTH_SHORT).show();
                } else {
                    Toast.makeText(ReadingGroups.this, "Failed to join the reading group", Toast.LENGTH_SHORT).show();
                }
            } catch (JSONException e) {
                e.printStackTrace();
            }
        };

        QueryRequest joinReadingGroupRequest = new QueryRequest.Builder(getString(R.string.url) + "join_groups.php", responseListener)
                .userId(userId)
                .groupId(groupId)
                .build();
        RequestQueue queue = Volley.newRequestQueue(ReadingGroups.this);
        queue.add(joinReadingGroupRequest);
    }
}
