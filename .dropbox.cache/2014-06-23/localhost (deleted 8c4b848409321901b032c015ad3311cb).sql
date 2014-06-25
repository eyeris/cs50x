-- phpMyAdmin SQL Dump
-- version 3.5.2.2
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Apr 11, 2013 at 02:01 AM
-- Server version: 5.5.28
-- PHP Version: 5.4.7

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `pset7`
--
CREATE DATABASE `pset7` DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci;
USE `pset7`;

-- --------------------------------------------------------

--
-- Table structure for table `event`
--

CREATE TABLE IF NOT EXISTS `event` (
  `evid` int(5) unsigned NOT NULL AUTO_INCREMENT,
  `id` int(10) unsigned NOT NULL,
  `title` text NOT NULL,
  `decription` text NOT NULL,
  `s_date` datetime NOT NULL,
  `s_pm` varchar(2) NOT NULL,
  `e_date` datetime NOT NULL,
  `e_pm` varchar(2) NOT NULL,
  `location` varchar(255) NOT NULL,
  PRIMARY KEY (`evid`),
  KEY `id` (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=9 ;

--
-- Dumping data for table `event`
--

INSERT INTO `event` (`evid`, `id`, `title`, `decription`, `s_date`, `s_pm`, `e_date`, `e_pm`, `location`) VALUES
(8, 19, 'This is event', 'dfgdsfgsdfg\r\nsfgsdfgsdf\r\ngsdfgsdfgsdfg', '2013-04-09 12:00:00', 'AM', '2013-04-26 11:00:00', 'PM', '');

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE IF NOT EXISTS `users` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `display` varchar(255) NOT NULL DEFAULT 'Guest',
  `username` varchar(255) NOT NULL,
  `email` varchar(255) NOT NULL,
  `hash` varchar(255) NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=21 ;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`id`, `display`, `username`, `email`, `hash`) VALUES
(18, 'B A Isura Nirmal', 'inirmal', 'isuranirmal@gmail.com', '$1$izkRS7A9$wcCGzhCNKQd5nk4TtWbLf0'),
(19, 'B A Isura Nirmal ', 'ini', 'isuranirmal@gmail.com', '$1$u9fF9p5w$u3jwas8iNw75j.hrgc.GC/'),
(20, 'B A Isura Nirmal', 'aaaaa', 'isuranirmal@gmail.com', '$1$A0HiZjFd$fdr/g7vTiLasyby32LKuL/');

--
-- Constraints for dumped tables
--

--
-- Constraints for table `event`
--
ALTER TABLE `event`
  ADD CONSTRAINT `event_ibfk_1` FOREIGN KEY (`id`) REFERENCES `users` (`id`) ON DELETE CASCADE;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
