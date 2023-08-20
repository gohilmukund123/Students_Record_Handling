
# Student's Records Handling
Hey there, this is Mukund Gohil. I have written a program using C++ for handling student's records. This program is designed to manage student information using text files as a database. It allows users to perform operations such as adding, viewing, searching, updating, and deleting student records. The program utilizes file input/output (I/O) operations to store and retrieve data from text files.
## Documentation

The program is written in C++ and follows a structured approach to interact with user data and files. It provides the following functionalities:

1. **Add Student Data:**
   - Allows the user to input student details, including name, age, degree, and semester number.
   - Generates a unique ID for each student.
   - Appends the student data to the "student.txt" file and updates the "id.txt" file.

2. **Show Student Data:**
   - Reads and displays all the student records stored in the "student.txt" file.

3. **Search Student Data:**
   - Prompts the user for a student ID to search for.
   - Scans the "student.txt" file for the provided ID and displays the student's information if found.

4. **Delete Student Data:**
   - Utilizes the search functionality to find and display student details.
   - Asks the user if they want to delete the displayed student record.
   - If confirmed, the program removes the corresponding student record from the "student.txt" file.

5. **Update Student Data:**
   - Uses the search feature to find and display the student's data.
   - Asks the user if they want to update the displayed student record.
   - If confirmed, the program allows the user to modify student information and saves the changes to the "student.txt" file.

6. **Exit Program:**
   - Terminates the program.
## Screenshots


## Deployment

(To deploy this project, you have to make a file named 'id.txt' and initialise it with a value.)

    1. Compile the program using a C++ compiler (e.g., g++).
    2. Run the compiled executable to start the program.
    3. Choose an operation by entering the corresponding operation number.
    4. Follow the prompts to input or manipulate student data.
## Usage/Examples

- The program uses file I/O for data storage, so make sure the program has permission to read and write files in the directory.
- User inputs, especially when reading strings with spaces, are handled using appropriate methods to prevent unexpected behavior.


**Data Storage**

The program stores student information in the "student.txt" file. Each student record is organized with the following format:

ID

Name

Age

Degree

Semester Number