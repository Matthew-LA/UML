package com.example.db3;

import android.os.Build;
import android.util.Log;

import com.android.volley.AuthFailureError;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.StringRequest;

import java.util.HashMap;
import java.util.Map;

public class QueryRequest extends StringRequest {
    private final Map<String, String> args;

    private QueryRequest(Builder builder) {
        super(Method.POST, builder.url, builder.listener, builder.errorListener);
        args = builder.args;
    }

    @Override
    protected Map<String, String> getParams() {
        return args;
    }

    public static class Builder {
        private final String url;
        private final Response.Listener<String> listener;
        private final Response.ErrorListener errorListener = error -> {
            Log.d("please", "Error listener response: " + error.getMessage());
            error.printStackTrace();
        };
        private final Map<String, String> args = new HashMap<>();

        public Builder(String url, Response.Listener<String> listener) {
            this.url = url;
            this.listener = listener;
        }

        public Builder email(String email) {
            args.put("email", email);
            return this;
        }

        public Builder password(String password) {
            args.put("password", password);
            return this;
        }

        public Builder name(String name) {
            args.put("name", name);
            return this;
        }

        public Builder phone(String phone) {
            args.put("phone", phone);
            return this;
        }

        public Builder userId(int userId) {
            args.put("userId", String.valueOf(userId));
            return this;
        }

        public Builder grade(int grade) {
            args.put("grade", String.valueOf(grade));
            return this;
        }

        public Builder groupId(int groupId) {
            args.put("groupId", String.valueOf(groupId));
            return this;
        }

        public Builder meetingId(int meetingId) {
            args.put("meetingId", String.valueOf(meetingId));
            return this;
        }

        public QueryRequest build() {
            return new QueryRequest(this);
        }
    }
}
