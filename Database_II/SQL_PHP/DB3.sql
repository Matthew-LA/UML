-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Generation Time: Apr 27, 2023 at 04:13 PM
-- Server version: 10.4.27-MariaDB
-- PHP Version: 8.2.0

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `DB3`
--

-- --------------------------------------------------------

--
-- Table structure for table `admins`
--

CREATE TABLE `admins` (
  `admin_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `admins`
--

INSERT INTO `admins` (`admin_id`) VALUES
(11);

-- --------------------------------------------------------

--
-- Table structure for table `child_of`
--

CREATE TABLE `child_of` (
  `student_id` int(11) NOT NULL,
  `parent_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `child_of`
--

INSERT INTO `child_of` (`student_id`, `parent_id`) VALUES
(1, 6),
(2, 7),
(3, 8),
(4, 9),
(5, 10);

-- --------------------------------------------------------

--
-- Table structure for table `enroll`
--

CREATE TABLE `enroll` (
  `meeting_id` int(11) NOT NULL,
  `student_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `enroll`
--

INSERT INTO `enroll` (`meeting_id`, `student_id`) VALUES
(2, 2),
(3, 3),
(4, 4),
(5, 5),
(6, 1),
(7, 2),
(8, 3),
(9, 4),
(10, 5);

-- --------------------------------------------------------

--
-- Table structure for table `groups`
--

CREATE TABLE `groups` (
  `group_id` int(11) NOT NULL,
  `group_name` varchar(255) NOT NULL,
  `description` varchar(255) DEFAULT NULL,
  `grade_req` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `groups`
--

INSERT INTO `groups` (`group_id`, `group_name`, `description`, `grade_req`) VALUES
(1, 'Biology 101', 'Group 1 for Biology 101', 10),
(2, 'Biology 102', 'Group 2 for Biology 101', 10),
(3, 'Chemistry 101', 'Group 1 for Chemistry 101', 11),
(4, 'Physics 101', 'Group 1 for Physics 101', 12),
(5, 'Physics 102', 'Group 2 for Physics 101', 12);

-- --------------------------------------------------------

--
-- Table structure for table `material`
--

CREATE TABLE `material` (
  `material_id` int(11) NOT NULL,
  `meeting_id` int(11) NOT NULL,
  `title` varchar(255) NOT NULL,
  `author` varchar(255) DEFAULT NULL,
  `type` varchar(255) DEFAULT NULL,
  `url` varchar(255) DEFAULT NULL,
  `notes` varchar(255) DEFAULT NULL,
  `assigned_date` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `material`
--

INSERT INTO `material` (`material_id`, `meeting_id`, `title`, `author`, `type`, `url`, `notes`, `assigned_date`) VALUES
(1, 1, 'Introduction to Biology', 'John Doe', 'Textbook', 'https://example.com/biology-textbook.pdf', 'Chapter 4-6', '2023-03-24'),
(2, 2, 'Introduction to Biology', 'John Doe', 'Textbook', 'https://example.com/biology-textbook.pdf', 'Chapter 4-6', '2023-03-24'),
(3, 6, 'Introduction to Biology', 'John Doe', 'Textbook', 'https://example.com/biology-textbook.pdf', 'Chapter 1-3', '2023-03-17'),
(4, 7, 'Introduction to Biology', 'John Doe', 'Textbook', 'https://example.com/biology-textbook.pdf', 'Chapter 1-3', '2023-03-17'),
(5, 8, 'Lab Safety Rules', NULL, 'Handout', 'https://example.com/lab-safety.pdf', NULL, '2023-03-17'),
(6, 3, 'Chemistry Quiz', NULL, 'Quiz', NULL, NULL, '2023-03-24'),
(7, 4, 'Physics Homework', 'Jane Smith', 'Assignment', NULL, NULL, '2023-03-24'),
(8, 5, 'Physics Homework', 'Jane Smith', 'Assignment', '', '', '2023-03-24'),
(9, 9, 'Presentation Slides', 'Mark Johnson', 'Presentation', 'https://example.com/presentation.pptx', NULL, '2023-03-17'),
(10, 10, 'Presentation Slides', 'Mark Johnson', 'Presentation', 'https://example.com/presentation.pptx', '', '2023-03-17');

-- --------------------------------------------------------

--
-- Table structure for table `meetings`
--

CREATE TABLE `meetings` (
  `meeting_id` int(11) NOT NULL,
  `meeting_name` varchar(255) NOT NULL,
  `date` date NOT NULL,
  `time_slot_id` int(11) NOT NULL,
  `capacity` int(11) NOT NULL,
  `group_id` int(11) NOT NULL,
  `announcement` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `meetings`
--

INSERT INTO `meetings` (`meeting_id`, `meeting_name`, `date`, `time_slot_id`, `capacity`, `group_id`, `announcement`) VALUES
(1, 'Biology 101 - Group 1', '2023-04-29', 1, 6, 1, 'Reminder: Bring your textbook'),
(2, 'Biology 102 - Group 2', '2023-04-29', 2, 6, 2, 'Canceled'),
(3, 'Chemistry 101 - Group 1', '2023-04-29', 3, 6, 3, 'Please bring your textbook'),
(4, 'Physics 101 - Group 1', '2023-04-29', 4, 6, 4, NULL),
(5, 'Physics 102 - Group 2', '2023-04-29', 5, 6, 5, 'Quiz today!'),
(6, 'Biology 101 - Group 1', '2023-04-22', 1, 6, 1, 'Reminder: homework is due next week'),
(7, 'Biology 102 - Group 2', '2023-04-22', 2, 6, 2, NULL),
(8, 'Chemistry 101 - Group 1', '2023-04-22', 3, 6, 3, 'Please bring your lab coat'),
(9, 'Physics 101 - Group 1', '2023-04-22', 4, 6, 4, NULL),
(10, 'Physics 102 - Group 2', '2023-04-22', 5, 6, 5, 'Quiz is next week');

-- --------------------------------------------------------

--
-- Table structure for table `member_of`
--

CREATE TABLE `member_of` (
  `group_id` int(11) NOT NULL,
  `student_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `member_of`
--

INSERT INTO `member_of` (`group_id`, `student_id`) VALUES
(1, 1),
(2, 2),
(3, 3),
(4, 4),
(5, 5);

-- --------------------------------------------------------

--
-- Table structure for table `notifications`
--

CREATE TABLE `notifications` (
  `note_id` int(255) NOT NULL,
  `user_id` int(255) NOT NULL,
  `note_date` date NOT NULL,
  `notification` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `notifications`
--

INSERT INTO `notifications` (`note_id`, `user_id`, `note_date`, `notification`) VALUES
(15, 2, '2023-03-30', 'The meeting \"Biology 102 - Group 2\" on 2023-04-01 from 10:00:00 to 11:00:00 for the \"Biology 102\" group has been canceled.');

-- --------------------------------------------------------

--
-- Table structure for table `parents`
--

CREATE TABLE `parents` (
  `parent_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `parents`
--

INSERT INTO `parents` (`parent_id`) VALUES
(6),
(7),
(8),
(9),
(10);

-- --------------------------------------------------------

--
-- Table structure for table `students`
--

CREATE TABLE `students` (
  `student_id` int(11) NOT NULL,
  `grade` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `students`
--

INSERT INTO `students` (`student_id`, `grade`) VALUES
(1, 10),
(2, 10),
(3, 11),
(4, 12),
(5, 12);

-- --------------------------------------------------------

--
-- Table structure for table `time_slot`
--

CREATE TABLE `time_slot` (
  `time_slot_id` int(11) NOT NULL,
  `day_of_the_week` varchar(255) NOT NULL,
  `start_time` time NOT NULL,
  `end_time` time NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `time_slot`
--

INSERT INTO `time_slot` (`time_slot_id`, `day_of_the_week`, `start_time`, `end_time`) VALUES
(1, 'Saturday', '09:00:00', '10:00:00'),
(2, 'Saturday', '10:00:00', '11:00:00'),
(3, 'Saturday', '11:00:00', '12:00:00'),
(4, 'Saturday', '12:00:00', '13:00:00'),
(5, 'Saturday', '13:00:00', '14:00:00'),
(6, 'Saturday', '14:00:00', '15:00:00'),
(7, 'Sunday', '09:00:00', '10:00:00'),
(8, 'Sunday', '10:00:00', '11:00:00'),
(9, 'Sunday', '11:00:00', '12:00:00'),
(10, 'Sunday', '12:00:00', '13:00:00'),
(11, 'Sunday', '13:00:00', '14:00:00'),
(12, 'Sunday', '14:00:00', '15:00:00');

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE `users` (
  `id` int(11) NOT NULL,
  `email` varchar(255) NOT NULL,
  `password` varchar(255) NOT NULL,
  `name` varchar(255) NOT NULL,
  `phone` varchar(255) DEFAULT NULL,
  `role` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`id`, `email`, `password`, `name`, `phone`, `role`) VALUES
(1, 'child1@g.com', '123', 'child1', '123', 'student'),
(2, 'child2@g.com', '123', 'child2', '123', 'student'),
(3, 'child3@g.com', '123', 'child3', '123', 'student'),
(4, 'child4@g.com', '123', 'child4', '123', 'student'),
(5, 'child5@g.com', '123', 'child5', '123', 'student'),
(6, 'parent1@g.com', '123', 'parent1', '123', 'parent'),
(7, 'parent2@g.com', '123', 'parent2', '123', 'parent'),
(8, 'parent3@g.com', '123', 'parent3', '123', 'parent'),
(9, 'parent4@g.com', '123', 'parent4', '123', 'parent'),
(10, 'parent5@g.com', '123', 'parent5', '123', 'parent'),
(11, 'admin', '123', 'admin', '123', 'admin');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `admins`
--
ALTER TABLE `admins`
  ADD PRIMARY KEY (`admin_id`);

--
-- Indexes for table `child_of`
--
ALTER TABLE `child_of`
  ADD PRIMARY KEY (`student_id`,`parent_id`),
  ADD KEY `parent_id` (`parent_id`);

--
-- Indexes for table `enroll`
--
ALTER TABLE `enroll`
  ADD PRIMARY KEY (`meeting_id`,`student_id`) USING BTREE,
  ADD KEY `student_id` (`student_id`);

--
-- Indexes for table `groups`
--
ALTER TABLE `groups`
  ADD PRIMARY KEY (`group_id`);

--
-- Indexes for table `material`
--
ALTER TABLE `material`
  ADD PRIMARY KEY (`material_id`,`meeting_id`),
  ADD KEY `meeting_id` (`meeting_id`);

--
-- Indexes for table `meetings`
--
ALTER TABLE `meetings`
  ADD PRIMARY KEY (`meeting_id`),
  ADD KEY `group_id` (`group_id`),
  ADD KEY `time_slot_id` (`time_slot_id`);

--
-- Indexes for table `member_of`
--
ALTER TABLE `member_of`
  ADD PRIMARY KEY (`group_id`,`student_id`),
  ADD KEY `student_id` (`student_id`);

--
-- Indexes for table `notifications`
--
ALTER TABLE `notifications`
  ADD PRIMARY KEY (`note_id`,`user_id`) USING BTREE,
  ADD KEY `user_id` (`user_id`);

--
-- Indexes for table `parents`
--
ALTER TABLE `parents`
  ADD PRIMARY KEY (`parent_id`);

--
-- Indexes for table `students`
--
ALTER TABLE `students`
  ADD PRIMARY KEY (`student_id`);

--
-- Indexes for table `time_slot`
--
ALTER TABLE `time_slot`
  ADD PRIMARY KEY (`time_slot_id`);

--
-- Indexes for table `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `notifications`
--
ALTER TABLE `notifications`
  MODIFY `note_id` int(255) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=18;

--
-- AUTO_INCREMENT for table `users`
--
ALTER TABLE `users`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=13;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `admins`
--
ALTER TABLE `admins`
  ADD CONSTRAINT `admins_ibfk_1` FOREIGN KEY (`admin_id`) REFERENCES `users` (`id`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `child_of`
--
ALTER TABLE `child_of`
  ADD CONSTRAINT `child_of_ibfk_1` FOREIGN KEY (`student_id`) REFERENCES `students` (`student_id`),
  ADD CONSTRAINT `child_of_ibfk_2` FOREIGN KEY (`parent_id`) REFERENCES `parents` (`parent_id`);

--
-- Constraints for table `enroll`
--
ALTER TABLE `enroll`
  ADD CONSTRAINT `enroll_ibfk_1` FOREIGN KEY (`student_id`) REFERENCES `students` (`student_id`),
  ADD CONSTRAINT `enroll_ibfk_2` FOREIGN KEY (`meeting_id`) REFERENCES `meetings` (`meeting_id`);

--
-- Constraints for table `material`
--
ALTER TABLE `material`
  ADD CONSTRAINT `material_ibfk_1` FOREIGN KEY (`meeting_id`) REFERENCES `meetings` (`meeting_id`) ON DELETE CASCADE;

--
-- Constraints for table `meetings`
--
ALTER TABLE `meetings`
  ADD CONSTRAINT `meetings_ibfk_1` FOREIGN KEY (`group_id`) REFERENCES `groups` (`group_id`),
  ADD CONSTRAINT `meetings_ibfk_2` FOREIGN KEY (`time_slot_id`) REFERENCES `time_slot` (`time_slot_id`);

--
-- Constraints for table `member_of`
--
ALTER TABLE `member_of`
  ADD CONSTRAINT `member_of_ibfk_1` FOREIGN KEY (`student_id`) REFERENCES `students` (`student_id`),
  ADD CONSTRAINT `member_of_ibfk_2` FOREIGN KEY (`group_id`) REFERENCES `groups` (`group_id`);

--
-- Constraints for table `parents`
--
ALTER TABLE `parents`
  ADD CONSTRAINT `parents_ibfk_1` FOREIGN KEY (`parent_id`) REFERENCES `users` (`id`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Constraints for table `students`
--
ALTER TABLE `students`
  ADD CONSTRAINT `students_ibfk_1` FOREIGN KEY (`student_id`) REFERENCES `users` (`id`) ON DELETE CASCADE ON UPDATE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
