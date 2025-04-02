# Road Damage Detection - Assignment 1

## 📌 Project Overview
This project is a **Road Damage Detection System** developed as part of **DSA Assignment 1**. It utilizes a machine learning model to identify potholes and cracks in road images. The project includes a Python script to process images and send email reports.

## 📁 Repository Structure
```
📂 DSA_Assignments
   📂 Assignment_1
       📂 venv/                     # Virtual environment (not included in repo)
       📂 dataset/                   # Images for detection
       📂 models/                    # Trained model files
       📂 scripts/                   # Helper scripts
       ├── send_email.py             # Script to send email reports
       ├── detect_potholes.py        # Main detection script
       ├── requirements.txt          # Dependencies list
       ├── README.md                 # Documentation
```

## 🛠️ Installation
### 1️⃣ Clone the Repository
```sh
git clone https://github.com/yourusername/road-damage-detection.git
cd road-damage-detection/Assignment_1
```

### 2️⃣ Set Up Virtual Environment
```sh
python -m venv venv
venv\Scripts\activate  # Windows
source venv/bin/activate  # macOS/Linux
```

### 3️⃣ Install Dependencies
```sh
pip install -r requirements.txt
```

## 🚀 How It Works
### 1️⃣ Run the Detection Script
To detect potholes in images, run:
```sh
python detect_potholes.py --image dataset/sample.jpg
```
This will process the image and output a detection result.

### 2️⃣ Send an Email Report
To send a detection report via email:
```sh
python send_email.py recipient@example.com "2025-04-02"
```
Replace `recipient@example.com` with the recipient's email address.

## 🛠️ Troubleshooting
If you encounter issues:
- Ensure your virtual environment is activated.
- Check if all dependencies are installed (`pip list`).
- Verify the Python path if running in PowerShell.

## 📝 License
This project is licensed under the **MIT License**.

## 💡 Contributing
Feel free to submit issues or pull requests to improve the project!

---
📩 **Contact:** [malakkalaabiadd@gmail.com ]
