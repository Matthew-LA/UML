package com.example.db3;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;
import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.toolbox.Volley;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;

public class GroupMeetings extends AppCompatActivity {
    private int userId;
    private ArrayList<Integer> joinAllIds = new ArrayList<Integer>();
    private ArrayList<Integer> leaveAllIds = new ArrayList<Integer>();
    private LinearLayout meetingsLayout;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_group_meetings);

        Intent intent = getIntent();
        userId = intent.getIntExtra("userId", -1);

        meetingsLayout = findViewById(R.id.meetingsLayout);

        fetchMeetings();

        Button homeButton = findViewById(R.id.homeButton);
        homeButton.setOnClickListener(view -> {
            Intent intent1 = new Intent(GroupMeetings.this, Dashboard.class);
            startActivity(intent1);
        });

        Button joinAllButton = findViewById(R.id.joinAllButton);
        joinAllButton.setOnClickListener(view -> joinAllMeetings());

        Button leaveAllButton = findViewById(R.id.leaveAllButton);
        leaveAllButton.setOnClickListener(view -> leaveAllMeetings());
    }

    private void fetchMeetings() {
        Response.Listener<String> responseListener = response -> {
            try {
                JSONObject jsonResponse = new JSONObject(response);
                boolean success = jsonResponse.getBoolean("success");

                if (success) {
                    JSONArray meetings = jsonResponse.getJSONArray("meetings");
                    if (meetings.length() == 0) {
                        Toast.makeText(GroupMeetings.this, "There are currently no meetings that can be enrolled in.", Toast.LENGTH_SHORT).show();
                    } else {
                        createMeetingList(meetings);
                    }
                } else {
                    Toast.makeText(GroupMeetings.this, "Failed to fetch meetings", Toast.LENGTH_SHORT).show();
                }
            } catch (JSONException e) {
                e.printStackTrace();
            }
        };

        QueryRequest queryRequest = new QueryRequest.Builder(getString(R.string.url) + "get_meetings.php", responseListener)
                .userId(userId)
                .build();
        RequestQueue queue = Volley.newRequestQueue(GroupMeetings.this);
        queue.add(queryRequest);
    }

    private void createMeetingList(JSONArray meetings) throws JSONException {
        for (int i = 0; i < meetings.length(); i++) {
            JSONObject meeting = meetings.getJSONObject(i);
            int meetingId = meeting.getInt("meetingId");
            String meetingName = meeting.getString("name");
            String date = meeting.getString("date");
            String startTime = meeting.getString("start_time");
            String endTime = meeting.getString("end_time");
            int enrolled = meeting.getInt("enrolled");

            TextView meetingTextView = new TextView(this);
            meetingTextView.setText("(" + date + ")" + meetingName + " " + startTime + "-" + endTime);
            meetingsLayout.addView(meetingTextView);

            if (enrolled == 0) {
                addButton("Join", meetingId, view -> joinMeeting(meetingId, true));
                joinAllIds.add(meetingId);
            } else {
                addButton("Leave", meetingId, view -> leaveMeeting(meetingId, true));
                leaveAllIds.add(meetingId);
            }

            addButton("View Students", meetingId, view -> viewStudents(meetingId));
        }
    }


    private void addButton(String text, int meetingId, View.OnClickListener onClickListener) {
        Button button = new Button(this);
        button.setText(text);
        button.setOnClickListener(onClickListener);
        meetingsLayout.addView(button);
    }

    private void joinMeeting(int meetingId, boolean refresh) {
        // Send a request to join_meeting.php
        Response.Listener<String> responseListener = response -> {
            try {
                JSONObject jsonResponse = new JSONObject(response);
                boolean success = jsonResponse.getBoolean("success");

                if (success) {
                    Toast.makeText(GroupMeetings.this, "Joined meeting successfully", Toast.LENGTH_SHORT).show();
                    if (refresh) {
                        refreshActivity();
                    }
                } else {
                    Toast.makeText(GroupMeetings.this, "Failed to join meeting", Toast.LENGTH_SHORT).show();
                }
            } catch (JSONException e) {
                e.printStackTrace();
            }
        };

        QueryRequest queryRequest = new QueryRequest.Builder(getString(R.string.url) + "join_meeting.php", responseListener)
                .userId(userId)
                .meetingId(meetingId)
                .build();
        RequestQueue queue = Volley.newRequestQueue(GroupMeetings.this);
        queue.add(queryRequest);
    }

    private void leaveMeeting(int meetingId, boolean refresh) {
        // Send a request to leave_meeting.php
        Response.Listener<String> responseListener = response -> {
            try {
                JSONObject jsonResponse = new JSONObject(response);
                boolean success = jsonResponse.getBoolean("success");

                if (success) {
                    Toast.makeText(GroupMeetings.this, "Left meeting successfully", Toast.LENGTH_SHORT).show();
                    if (refresh) {
                        refreshActivity();
                    }
                } else {
                    Toast.makeText(GroupMeetings.this, "Failed to leave meeting", Toast.LENGTH_SHORT).show();
                }
            } catch (JSONException e) {
                e.printStackTrace();
            }
        };

        QueryRequest queryRequest = new QueryRequest.Builder(getString(R.string.url) + "leave_meeting.php", responseListener)
                .userId(userId)
                .meetingId(meetingId)
                .build();
        RequestQueue queue = Volley.newRequestQueue(GroupMeetings.this);
        queue.add(queryRequest);
    }

    private void viewStudents(int meetingId) {
        // Send a request to get_students.php
        Response.Listener<String> responseListener = response -> {
            try {
                JSONObject jsonResponse = new JSONObject(response);
                boolean success = jsonResponse.getBoolean("success");

                if (success) {
                    JSONArray students = jsonResponse.getJSONArray("students");
                    // Display the list of students in a dialog
                    AlertDialog.Builder builder = new AlertDialog.Builder(GroupMeetings.this);
                    LayoutInflater inflater = getLayoutInflater();
                    View dialogView = inflater.inflate(R.layout.student_list_dialog, null);
                    builder.setView(dialogView);

                    ListView studentList = dialogView.findViewById(R.id.student_list);
                    ArrayList<String> studentNames = new ArrayList<>();

                    for (int i = 0; i < students.length(); i++) {
                        JSONObject student = students.getJSONObject(i);
                        studentNames.add(student.getString("name") + " (" + student.getString("email") + ")");
                    }

                    ArrayAdapter<String> adapter = new ArrayAdapter<>(GroupMeetings.this, android.R.layout.simple_list_item_1, studentNames);
                    studentList.setAdapter(adapter);

                    builder.setTitle("Students in the Meeting")
                            .setPositiveButton("Close", (dialog, which) -> dialog.dismiss());

                    AlertDialog alertDialog = builder.create();
                    alertDialog.show();
                } else {
                    Toast.makeText(GroupMeetings.this, "Failed to fetch students", Toast.LENGTH_SHORT).show();
                }
            } catch (JSONException e) {
                e.printStackTrace();
            }
        };

        QueryRequest queryRequest = new QueryRequest.Builder(getString(R.string.url) + "get_students.php", responseListener)
                .meetingId(meetingId)
                .build();
        RequestQueue queue = Volley.newRequestQueue(GroupMeetings.this);
        queue.add(queryRequest);
    }

    private void refreshActivity() {
        Intent intent = new Intent(GroupMeetings.this, GroupMeetings.class);
        intent.putExtra("userId", userId);
        startActivity(intent);
    }

    private void joinAllMeetings() {
        for (int i = 0; i < joinAllIds.size(); i++) {
            int meetingId = joinAllIds.get(i);
            boolean refresh = (i == joinAllIds.size() - 1);
            joinMeeting(meetingId, refresh);
        }
    }

    private void leaveAllMeetings() {
        for (int i = 0; i < leaveAllIds.size(); i++) {
            int meetingId = leaveAllIds.get(i);
            boolean refresh = (i == leaveAllIds.size() - 1);
            leaveMeeting(meetingId, refresh);
        }
    }

}

