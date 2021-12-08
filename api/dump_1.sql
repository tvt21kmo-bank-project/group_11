CREATE DATABASE  IF NOT EXISTS `pankki` /*!40100 DEFAULT CHARACTER SET utf8 */ /*!80016 DEFAULT ENCRYPTION='N' */;
USE `pankki`;
-- MySQL dump 10.13  Distrib 8.0.26, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: pankki
-- ------------------------------------------------------
-- Server version	8.0.23

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `asiakas`
--

DROP TABLE IF EXISTS `asiakas`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `asiakas` (
  `idAsiakas` int NOT NULL AUTO_INCREMENT,
  `Etunimi` varchar(45) DEFAULT NULL,
  `Sukunimi` varchar(45) DEFAULT NULL,
  `Lahiosoite` varchar(45) DEFAULT NULL,
  `Puhelinnumero` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`idAsiakas`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `asiakas`
--

LOCK TABLES `asiakas` WRITE;
/*!40000 ALTER TABLE `asiakas` DISABLE KEYS */;
INSERT INTO `asiakas` VALUES (1,'Testi','Teppo','Testitie 1','040 56565'),(2,'Testi','Kaali','testikatu 3','050 565698');
/*!40000 ALTER TABLE `asiakas` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `asiakas_tili`
--

DROP TABLE IF EXISTS `asiakas_tili`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `asiakas_tili` (
  `idAsiakas` int NOT NULL,
  `idTili` int NOT NULL,
  KEY `fk_asiakas_has_Tili_Tili1_idx` (`idTili`),
  KEY `fk_asiakas_has_Tili_asiakas_idx` (`idAsiakas`),
  CONSTRAINT `fk_asiakas_has_Tili_asiakas` FOREIGN KEY (`idAsiakas`) REFERENCES `asiakas` (`idAsiakas`),
  CONSTRAINT `fk_asiakas_has_Tili_Tili1` FOREIGN KEY (`idTili`) REFERENCES `tili` (`idTili`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `asiakas_tili`
--

LOCK TABLES `asiakas_tili` WRITE;
/*!40000 ALTER TABLE `asiakas_tili` DISABLE KEYS */;
/*!40000 ALTER TABLE `asiakas_tili` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `kortti`
--

DROP TABLE IF EXISTS `kortti`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `kortti` (
  `idKortti` int NOT NULL AUTO_INCREMENT,
  `Korttinumero` varchar(45) DEFAULT NULL,
  `PIN` varchar(255) DEFAULT NULL,
  `idAsiakas` int NOT NULL,
  `idTili` int NOT NULL,
  PRIMARY KEY (`idKortti`),
  UNIQUE KEY `Korttinumero_UNIQUE` (`Korttinumero`),
  KEY `fk_kortti_asiakas1_idx` (`idAsiakas`),
  KEY `fk_Kortti_Tili1_idx` (`idTili`),
  CONSTRAINT `fk_kortti_asiakas1` FOREIGN KEY (`idAsiakas`) REFERENCES `asiakas` (`idAsiakas`),
  CONSTRAINT `fk_Kortti_Tili1` FOREIGN KEY (`idTili`) REFERENCES `tili` (`idTili`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `kortti`
--

LOCK TABLES `kortti` WRITE;
/*!40000 ALTER TABLE `kortti` DISABLE KEYS */;
INSERT INTO `kortti` VALUES (3,'2222','$2a$10$3cI0/uVEKQaK/ezIh/hM4uqbrDsZ/gS4msPOIWmqoFkHQY9VNdfua',1,2),(6,'4444','$2a$10$Xi86DWrHw/msX6G83e.aiOSAuKczL63GmDq/.ilRdsRQqcSr5ZVte',2,7),(8,'6666','$2a$10$tw84YfA5XPV6kX72SKkTxuRl5vJEPF9tDMJAcIWH5e/KMj4XzgNsC',2,3);
/*!40000 ALTER TABLE `kortti` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tili`
--

DROP TABLE IF EXISTS `tili`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `tili` (
  `idTili` int NOT NULL AUTO_INCREMENT,
  `idOmistaja` int DEFAULT NULL,
  `Tilinumero` varchar(45) DEFAULT NULL,
  `Saldo` float DEFAULT NULL,
  `Tilin_tyyppi` varchar(45) DEFAULT NULL,
  `Luottoraja` float DEFAULT NULL,
  PRIMARY KEY (`idTili`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tili`
--

LOCK TABLES `tili` WRITE;
/*!40000 ALTER TABLE `tili` DISABLE KEYS */;
INSERT INTO `tili` VALUES (2,1,'1000',5000,'Credit',500),(3,2,'2222',2000,'Credit',5000),(7,2,'22222',2000,'Debit',0);
/*!40000 ALTER TABLE `tili` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tilitapahtumat`
--

DROP TABLE IF EXISTS `tilitapahtumat`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `tilitapahtumat` (
  `idTilitapahtumat` int NOT NULL AUTO_INCREMENT,
  `Paivays` datetime DEFAULT NULL,
  `Tapahtuma` varchar(45) DEFAULT NULL,
  `Summa` float DEFAULT NULL,
  `idTili` int NOT NULL,
  `idKortti` int NOT NULL,
  PRIMARY KEY (`idTilitapahtumat`),
  KEY `fk_Tilitapahtumat_Tili1_idx` (`idTili`,`idKortti`),
  CONSTRAINT `fk_Tilitapahtumat_Tili1` FOREIGN KEY (`idTili`) REFERENCES `tili` (`idTili`)
) ENGINE=InnoDB AUTO_INCREMENT=65 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tilitapahtumat`
--

LOCK TABLES `tilitapahtumat` WRITE;
/*!40000 ALTER TABLE `tilitapahtumat` DISABLE KEYS */;
INSERT INTO `tilitapahtumat` VALUES (38,'2021-12-08 12:22:10','credit_Nosto',10,2,3),(39,'2021-12-08 12:24:43','credit_Nosto',10,2,3),(40,'2021-12-08 12:27:31','credit_Nosto',10,2,3),(41,'2021-12-08 12:28:50','credit_Nosto',10,2,3),(42,'2021-12-08 12:31:02','credit_Nosto',10,2,3),(43,'2021-12-08 12:43:44','credit_Nosto',10,2,3),(44,'2021-12-08 12:44:00','credit_Nosto',20,2,3),(45,'2021-12-08 12:44:19','credit_Nosto',40,2,3),(46,'2021-12-08 12:44:31','credit_Nosto',60,2,3),(47,'2021-12-08 12:44:33','credit_Nosto',100,2,3),(48,'2021-12-08 12:44:36','credit_Nosto',200,2,3),(49,'2021-12-08 12:44:37','credit_Nosto',500,2,3),(50,'2021-12-08 12:44:56','credit_Nosto',65,2,3),(51,'2021-12-08 12:49:29','credit_Nosto',10,2,3),(52,'2021-12-08 12:49:43','credit_Nosto',20,2,3),(53,'2021-12-08 12:49:43','credit_Nosto',40,2,3),(54,'2021-12-08 12:49:44','credit_Nosto',60,2,3),(55,'2021-12-08 12:49:45','credit_Nosto',100,2,3),(56,'2021-12-08 12:49:45','credit_Nosto',200,2,3),(57,'2021-12-08 12:49:46','credit_Nosto',500,2,3),(58,'2021-12-08 12:49:49','credit_Nosto',55,2,3),(59,'2021-12-08 12:51:09','credit_Nosto',10,2,3),(60,'2021-12-08 12:51:11','credit_Nosto',20,2,3),(61,'2021-12-08 12:51:12','credit_Nosto',10,2,3),(62,'2021-12-08 12:52:31','credit_Nosto',10,2,3),(63,'2021-12-08 12:52:33','credit_Nosto',20,2,3),(64,'2021-12-08 12:52:35','credit_Nosto',40,2,3);
/*!40000 ALTER TABLE `tilitapahtumat` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping routines for database 'pankki'
--
/*!50003 DROP PROCEDURE IF EXISTS `credit_nosto` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `credit_nosto`(IN first_id INT, IN second_id INT, IN Summa DOUBLE )
BEGIN
  DECLARE test1 INT DEFAULT 0;
  START TRANSACTION;
  UPDATE Tili SET Saldo=Saldo-Summa WHERE idTili=first_id AND Saldo>=(-Luottoraja+1) AND (Tilin_tyyppi = 'Credit' OR Tilin_tyyppi = 'credit' OR Tilin_tyyppi = 'Both' OR Tilin_tyyppi = 'both');
  SET test1=ROW_COUNT();
    IF (test1 > 0) THEN   
      COMMIT;    
      INSERT INTO Tilitapahtumat(Paivays,Tapahtuma,Summa,idTili,idKortti) VALUES(NOW(),'credit_Nosto',Summa, first_id,second_id);
    ELSE
      ROLLBACK;
  END IF;
  END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `debit_nosto` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `debit_nosto`(IN first_id INT, IN second_id INT, IN Summa DOUBLE )
BEGIN
  DECLARE test1 INT DEFAULT 0;
  START TRANSACTION;
  UPDATE Tili SET Saldo=Saldo-Summa WHERE idTili=first_id AND Saldo>=Summa AND (Tilin_tyyppi = 'Debit' OR Tilin_tyyppi = 'debit' OR Tilin_tyyppi = 'Both' OR Tilin_tyyppi = 'both');
  SET test1=ROW_COUNT();
    IF (test1 > 0) THEN   
      COMMIT;    
      INSERT INTO Tilitapahtumat(Paivays,Tapahtuma,Summa,idTili,idKortti) VALUES(NOW(),'debit_Nosto',Summa, first_id,second_id);
    ELSE
      ROLLBACK;
  END IF;
  END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2021-12-08 13:27:42
