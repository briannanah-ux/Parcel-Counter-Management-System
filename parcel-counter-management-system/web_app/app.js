import { initializeApp } from "https://www.gstatic.com/firebasejs/9.6.10/firebase-app.js";
import { getDatabase, ref, onValue } from "https://www.gstatic.com/firebasejs/9.6.10/firebase-database.js";

// --- Firebase Config (replace with your own project details) ---
const firebaseConfig = {
  apiKey: "YOUR_API_KEY",
  authDomain: "your-project.firebaseapp.com",
  databaseURL: "https://your-project.firebaseio.com",
  projectId: "your-project",
  storageBucket: "your-project.appspot.com",
  messagingSenderId: "000000000000",
  appId: "YOUR_APP_ID"
};

// --- Initialize Firebase ---
const app = initializeApp(firebaseConfig);
const db = getDatabase(app);

const container = document.getElementById("locker-container");

// Render 3 lockers initially
for (let i = 0; i < 3; i++) {
  const div = document.createElement("div");
  div.className = "locker available";
  div.id = `locker-${i}`;
  div.innerHTML = `
    <h2>Locker ${i}</h2>
    <span>Status: Available</span>
    <span>User ID: -</span>
  `;
  container.appendChild(div);
}

// Listen for Firebase updates
for (let i = 0; i < 3; i++) {
  const path = `lockers/locker${i}`;
  const lockerRef = ref(db, path);

  onValue(lockerRef, (snapshot) => {
    const data = snapshot.val();
    const div = document.getElementById(`locker-${i}`);
    if (!div) return;

    if (data) {
      const occupied = data.occupied ? "occupied" : "available";
      div.className = `locker ${occupied}`;
      div.innerHTML = `
        <h2>Locker ${i}</h2>
        <span>Status: ${data.occupied ? "Occupied" : "Available"}</span>
        <span>User ID: ${data.userId ?? "-"}</span>
      `;
    }
  });
}

console.log("Firebase dashboard running...");
