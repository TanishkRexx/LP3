
// SPDX-License-Identifier: MIT
pragma solidity ^0.8.20;

contract StudentData {

    // Structure to store student information
    struct Student {
        uint id;
        string name;
        uint age;
        string course;
    }

    // Dynamic array to store student records
    Student[] public students;

    // Function to add a student
    function addStudent(
        uint id,
        string memory name,
        uint age,
        string memory course
    ) public {
        students.push(Student(id, name, age, course));
    }

    // Function to retrieve student details
    function getStudent(uint index)
        public
        view
        returns (uint, string memory, uint, string memory)
    {
        require(index < students.length, "Invalid student index");

        Student memory s = students[index];

        return (s.id, s.name, s.age, s.course);
    }

    // Function to receive Ether directly
    receive() external payable {
    }

    // Fallback function
    fallback() external payable {
    }
}
