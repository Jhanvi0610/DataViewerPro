# Data Viewer Pro —  Data Log Application for Embedded Systems

A real-time data logging application built for embedded systems (ES). 
It stores and manages live data from different modules of the embedded system using SQLite, with a Qt-based GUI and backend.

## Features
- Insert and extract data files
- Filter data by date range, valve name, and sensor name
- Search across records
- Export extracted data to CSV and Excel
- Displays extracted data (timestamp, operation ID, valve/sensor values) in a structured table view

## Tech Stack
- **GUI & Backend:** Qt (C++)
- **Database:** SQLite
- **Platform:** Developed and tested on RHEL (Linux)

## Note on Sample Data
The sample data included is synthetic and used only to demonstrate functionality — it does not represent real embedded system or sensor data.

## Getting Started
1. Clone the repo
2. Open `DataLogin.pro` in Qt Creator
3. Build and run (Qt 6.x with MinGW or your configured kit)
4. Use "Insert File" to load a sample `.db` file, then "Extract Data" to view it
