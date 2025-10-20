import { initializeApp } from "https://www.gstatic.com/firebasejs/9.6.10/firebase-app.js";
import { getDatabase, ref, onValue } from "https://www.gstatic.com/firebasejs/9.6.10/firebase-database.js";

// --- Firebase Config (replace with your own) ---
const firebaseConfig = {
  apiKey: "YOUR_API_KEY",
  authDomain: "your-project.firebaseapp.com",
  databaseURL: "https://your-project.firebaseio.com",
  projectId: "your-project",
  storageBucket: "your-project.appspot.com",
  messagingSenderId: "000000000000",
  appId: "YOUR_APP_ID"
};

// Initialize Firebase
const app = initializeApp(firebaseConfig);
const db = getDatabase(app);

const logsDiv = document.getElementById("logs");

// Utility: format timestamp to readable date
function formatTime(ts) {
  const d = new Date(ts * 1000);
  return d.toLocaleString();
}

// Listen to /attendance updates for all 3 lockers
for (let i = 0; i < 3; i++) {
  const logRef = ref(db, `attendance/locker${i}`);
  onValue(logRef, (snapshot) => {
    const data = snapshot.val();
    renderLogs(i, data);
  });
}

// Render function
function renderLogs(lockerId, data) {
  if (!data) return;
  const entries = Object.entries(data).sort((a, b) => b[1].ts - a[1].ts); // newest first

  let html = `<h3>Locker ${lockerId}</h3><table><tr>
                <th>Time</th><th>User ID</th><th>Status</th></tr>`;

  entries.forEach(([key, val]) => {
    const time = formatTime(val.ts || 0);
    const user = val.userId ?? "-";
    const status = val.occupied ? "Occupied" : "Cleared";
    html += `<tr>
               <td>${time}</td>
               <td>${user}</td>
               <td>${status}</td>
             </tr>`;
  });
  html += "</table>";

  // If container for this locker doesn’t exist, create it
  let lockerDiv = document.getElementById(`locker-logs-${lockerId}`);
  if (!lockerDiv) {
    lockerDiv = document.createElement("div");
    lockerDiv.id = `locker-logs-${lockerId}`;
    lockerDiv.className = "log-block";
    logsDiv.appendChild(lockerDiv);
  }
  lockerDiv.innerHTML = html;
}
