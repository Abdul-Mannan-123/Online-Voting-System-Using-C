# 🗳️ Online Voting System (C | Programming Fundamentals Project)

## 📝 Overview
The **Online Voting System** is a console-based C application developed as part of a **Semester 1 Programming Fundamentals (PF)** project.  
It allows registered voters to log in, cast their votes for one of four candidates, and view live election statistics and results.  
This project demonstrates the use of **structures**, **file handling**, **conditionals**, **loops**, and **functions** in C.

---

## 🚀 Features
- 👤 **Voter Authentication** using unique ID and password  
- ✅ **Prevents double voting** (tracks if a voter has already voted)  
- 🗳️ **Vote casting** for one of four candidates  
- 📊 **Real-time vote counting and results**  
- 🏆 **Displays the leading candidate**  
- 💾 **Reads voter data from a file (`voters.txt`)**  

---

## 💡 Concepts Used
| Concept | Implementation |
|----------|----------------|
| **Structures** | Used for `Voter` data storage (ID, password, voting status) |
| **File Handling** | Reads voter credentials from `voters.txt` |
| **Conditional Logic** | Used for authentication and vote validation |
| **Loops** | Iterates through voters and menu options |
| **Functions** | Modular design for voting, counting, and results |

---

## 📂 File Structure
Online-Voting-System/
│
├── main.c # Main program source file
├── voters.txt # Text file containing voter IDs and passwords
└── README.md # Project documentation

---

## ⚙️ How to Run
1. Clone or download the repository:
   ```bash
   git clone https://github.com/<your-username>/Online-Voting-System.git
   cd Online-Voting-System
   gcc main.c -o voting
   ./voting

---

## 📘 Example voters.txt File

**Each line should contain a voter ID and password separated by a space:**

101 password1
102 password2
103 password3
104 password4

## 🧠 Example Operations
.... Welcome to Online Voting ....
1. Cast the Vote
2. Find Vote Count
3. Find Leading Candidate
0. Exit
Please enter your choice: 1

### Please enter your ID and Password ###
ID: 101
Password: password1

### Please choose your Candidate ###
1. ALPHA
2. BRAVO
3. CHARLIE
4. DELTA
5. None of These

Input your choice (1 - 4): 3
Thanks for voting!!

## 🏆 Sample Output
.... Voting Statistics ....
ALPHA - 2
BRAVO - 3
CHARLIE - 5
DELTA - 1
Spoiled Votes - 0

.... Leading Candidate ....
CHARLIE
👨‍💻 Author

## Abdul Mannan
🎓 BS Computer Science — National University of Computer and Emerging Sciences
📅 Year 1, Semester 1

