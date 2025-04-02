# Iftar Invitation Management System

## Description
This project is a Python-based Object-Oriented program designed to help Fatima track Iftar invitations for her friends and family. The system allows her to store guest information, update invitations, send reminders, and sort the guest list by date.

## Features
- Store guest details including name, contact, and invitation date.
- Display a list of all invited guests.
- Update invitation details if guests are added or removed.
- Send reminder emails to guests on a specific date.
- Sort the guest list by invitation date using a sorting algorithm.
- Includes test cases to ensure the program functions correctly.

## Classes and Methods
### `Guest` Class
Each guest has the following attributes:
- `name` (string) – Guest's name.
- `contact` (string) – Guest's phone number or email.
- `iftar_date` (string) – Date of invitation.

Methods:
- `display_guest()`: Prints guest details.
- `update_invitation(new_date)`: Updates the invitation date.

### `IftarManager` Class
Manages multiple invitations:
- `guest_list` (list) – Stores multiple `Guest` objects.

Methods:
- `add_guest(guest)`: Adds a new guest.
- `display_all_guests()`: Displays all invited guests.
- `update_guest_invitation(name, new_date)`: Updates a guest's invitation date.
- `send_reminder(date)`: Sends reminder messages to guests via email.
- `sort_guest_list()`: Sorts guests by invitation date.

## How It Works
1. Clone the repository:
   ```bash
   git clone https://github.com/Malak-Alaabiad/Data-Structure_Assignment-1.git
   ```
2. Navigate to the project directory:
   ```bash
   cd Data-Structure_Assignment-1
   ```
3. Run the main script:
   ```bash
   python main.py
   ```

### Example Usage
```python
# Create Iftar Manager
manager = IftarManager()

# Add guests
guest1 = Guest("Aisha", "aisha@example.com", "2025-03-15")
guest2 = Guest("Omar", "omar@example.com", "2025-03-18")
guest3 = Guest("Zainab", "zainab@example.com", "2025-03-20")
manager.add_guest(guest1)
manager.add_guest(guest2)
manager.add_guest(guest3)

# Display guest list
manager.display_all_guests()

# Update invitation date
manager.update_guest_invitation("Omar", "2025-03-15")

# Send reminders
manager.send_reminder("2025-03-15")
```

### Expected Output
```
Guest: Aisha, Contact: aisha@example.com, Iftar Date: 2025-03-15
Guest: Omar, Contact: omar@example.com, Iftar Date: 2025-03-18
Guest: Zainab, Contact: zainab@example.com, Iftar Date: 2025-03-20
Updating invitation for Omar...
Guest: Aisha, Contact: aisha@example.com, Iftar Date: 2025-03-15
Guest: Omar, Contact: omar@example.com, Iftar Date: 2025-03-15
Guest: Zainab, Contact: zainab@example.com, Iftar Date: 2025-03-20
Sending reminders...
Reminder sent to Aisha: Your Iftar invitation is on 2025-03-15!
Reminder sent to Omar: Your Iftar invitation is on 2025-03-15!
May your Iftar gatherings be full of warmth and blessings!
```

## Running Test Cases
To run test cases, execute:
```bash
python test_iftar_manager.py
```

## Dependencies
- Python 3.x
- smtplib (for sending emails)

## Author
Malak Alabiad

---
Enjoy organizing your Iftar invitations! 🌙
