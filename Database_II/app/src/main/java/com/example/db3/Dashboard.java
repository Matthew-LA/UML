package com.example.db3;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

public class Dashboard extends AppCompatActivity {
    private int userId, childId, grade;
    private String role;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_dashboard);

        // Get Users info
        UserSession userSession = (UserSession) getApplicationContext();
        userId = userSession.getUserId();
        role = userSession.getRole();
        childId = userSession.getChildId();
        grade = userSession.getGrade();
        Log.d("please", "UserID: " + userId + " Grade: " + grade);

        TextView welcomeTextView = findViewById(R.id.welcomeTextView);
        TextView userInfoTextView = findViewById(R.id.userInfoTextView);
        userInfoTextView.setText("Welcome " + role + "!");

        Button buttonUpdateMyDetails = findViewById(R.id.buttonUpdateMyDetails);
        Button buttonUpdateChildDetails = findViewById(R.id.buttonUpdateChildDetails);
        Button buttonRegisterForReadingGroup = findViewById(R.id.buttonRegisterForReadingGroup);
        Button buttonUpdateUserDetails = findViewById(R.id.buttonUpdateUserDetails);
        Button buttonJoinMeet = findViewById(R.id.buttonJoinMeet);
        Button buttonMeetMats = findViewById(R.id.buttonMeetMats);

        // Initially set all buttons to View.GONE
        buttonUpdateMyDetails.setVisibility(View.GONE);
        buttonUpdateChildDetails.setVisibility(View.GONE);
        buttonRegisterForReadingGroup.setVisibility(View.GONE);
        buttonUpdateUserDetails.setVisibility(View.GONE);
        buttonJoinMeet.setVisibility(View.GONE);
        buttonMeetMats.setVisibility(View.GONE);

        // Show the buttons based on user role
        if (role.equals("parent")) {
            buttonJoinMeet.setText("Enroll Child in a Meeting");
            buttonJoinMeet.setVisibility(View.VISIBLE);
            buttonMeetMats.setText("View Child's Meeting Materials");
            buttonMeetMats.setVisibility(View.VISIBLE);
            buttonUpdateMyDetails.setVisibility(View.VISIBLE);
            buttonUpdateChildDetails.setVisibility(View.VISIBLE);

            buttonMeetMats.setOnClickListener(view -> openActivity(MeetMats.class, childId));
            buttonJoinMeet.setOnClickListener(view -> openActivity(GroupMeetings.class, childId));
            buttonUpdateMyDetails.setOnClickListener(view -> openActivity(UpdateUser.class, userId));
            buttonUpdateChildDetails.setOnClickListener(view -> openActivity(UpdateUser.class, childId));

        } else if (role.equals("student")) {
            buttonRegisterForReadingGroup.setVisibility(View.VISIBLE);
            buttonJoinMeet.setVisibility(View.VISIBLE);
            buttonUpdateUserDetails.setVisibility(View.VISIBLE);
            buttonMeetMats.setVisibility(View.VISIBLE);

            buttonRegisterForReadingGroup.setOnClickListener(view -> openActivity(ReadingGroups.class, userId, grade));
            buttonJoinMeet.setOnClickListener(view -> openActivity(GroupMeetings.class, userId));
            buttonMeetMats.setOnClickListener(view -> openActivity(MeetMats.class, userId));
            buttonUpdateUserDetails.setOnClickListener(view -> openActivity(UpdateUser.class, userId));
        }

        // Create the logout button
        Button logoutButton = findViewById(R.id.logoutButton);
        logoutButton.setOnClickListener(view -> {
            Intent intent = new Intent(Dashboard.this, Login.class);
            intent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK | Intent.FLAG_ACTIVITY_CLEAR_TASK);
            startActivity(intent);
        });
    }

    private void openActivity(Class<?> activityClass, int id) {
        Intent intent = new Intent(Dashboard.this, activityClass);
        intent.putExtra("userId", id);
        startActivity(intent);
    }

    private void openActivity(Class<?> activityClass, int id, int grade) {
        Intent intent = new Intent(Dashboard.this, activityClass);
        intent.putExtra("userId", id);
        intent.putExtra("grade", grade);
        startActivity(intent);
    }
}

