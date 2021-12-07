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
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `kortti`
--

LOCK TABLES `kortti` WRITE;
/*!40000 ALTER TABLE `kortti` DISABLE KEYS */;
INSERT INTO `kortti` VALUES (3,'16546465464','$2a$10$Hmd1fX1KrrNOYtE7CkoLu.latbj6xMIYfBNict.Oo7QEahMBGZS5a',1,2),(4,'123456','$2a$10$VI5uWICs0TLpUT.tAVCctOVFbVgoMs1CmFR1Bj4QvI41NptfNc6gK',2,5),(5,'1234567','$2a$10$HDYhGg9mRqVL7J1qPdA6Kevn70qePPvUOJVJmTniW9UtsBjP2Vo1K',2,6),(6,'12345678','$2a$10$Qy6dKCgdUVy8MfdhBX5b6uM.7h0kQWrOyvx3Gw3tbRqUdkfeVMYki',2,7),(7,'123456789','$2a$10$nhBtZHszRvPV2KysO3WmwONxqKomUm5254bT9Y3NomACFV0Xv4nDe',2,8);
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
INSERT INTO `tili` VALUES (2,1,'1000',97,'Credit',111),(3,1,'1000',123,'Debit',111),(4,1,'1000',122,'credit',111),(5,2,'11111',122,'Both',111),(6,2,'22222',92,'both',111),(7,2,'22222',0,'Debit',111),(8,2,'22222',7,'debit',111);
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
) ENGINE=InnoDB AUTO_INCREMENT=24 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tilitapahtumat`
--

LOCK TABLES `tilitapahtumat` WRITE;
/*!40000 ALTER TABLE `tilitapahtumat` DISABLE KEYS */;
INSERT INTO `tilitapahtumat` VALUES (4,'2021-12-02 19:37:52','Nosto',1,2,3),(5,'2021-12-02 19:40:55','Nosto',10,2,3),(6,'2021-12-02 19:41:31','Nosto',112,2,3),(7,'2021-12-02 19:44:08','Nosto',100,2,3),(8,'2021-12-02 19:44:21','Nosto',11,2,3),(9,'2021-12-02 19:50:13','Nosto',100,2,3),(10,'2021-12-02 19:50:33','Nosto',111,2,3),(11,'2021-12-02 20:00:51','Nosto',1,2,3),(12,'2021-12-02 20:09:05','Nosto',1,2,3),(13,'2021-12-02 20:09:49','Nosto',1,4,3),(14,'2021-12-03 16:02:01','Nosto',1,2,3),(15,'2021-12-03 16:05:05','Nosto',1,5,4),(16,'2021-12-03 16:06:25','Nosto',1,6,5),(17,'2021-12-03 16:11:30','Nosto',15,6,5),(18,'2021-12-03 16:14:50','Nosto',10,7,6),(19,'2021-12-03 16:16:04','Nosto',113,7,6),(20,'2021-12-03 16:16:26','Nosto',113,8,7),(21,'2021-12-03 16:18:10','credit_Nosto',15,6,5),(22,'2021-12-03 16:18:23','debit_Nosto',1,8,7),(23,'2021-12-07 21:04:59','debit_Nosto',2,8,7);
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

-- Dump completed on 2021-12-07 21:11:36
