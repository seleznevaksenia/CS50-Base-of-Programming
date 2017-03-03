-- MySQL dump 10.13  Distrib 5.5.49, for debian-linux-gnu (x86_64)
--
-- Host: 0.0.0.0    Database: pset7
-- ------------------------------------------------------
-- Server version	5.5.49-0ubuntu0.14.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `History`
--

DROP TABLE IF EXISTS `History`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `History` (
  `operation_id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `transaction` varchar(10) NOT NULL,
  `symbol` varchar(10) NOT NULL,
  `number` int(11) NOT NULL,
  `price` decimal(10,0) NOT NULL,
  `time` datetime NOT NULL,
  `user_id` int(10) unsigned NOT NULL,
  PRIMARY KEY (`operation_id`),
  UNIQUE KEY `operation_id` (`operation_id`)
) ENGINE=InnoDB AUTO_INCREMENT=38 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `History`
--

LOCK TABLES `History` WRITE;
/*!40000 ALTER TABLE `History` DISABLE KEYS */;
INSERT INTO `History` VALUES (1,'SELL','R',6,67,'0000-00-00 00:00:00',0),(2,'SELL','Y',1,513,'0000-00-00 00:00:00',0),(3,'BUY','F',1,12,'0000-00-00 00:00:00',0),(4,'SELL','F',12,12,'0000-00-00 00:00:00',0),(5,'SELL','D',147,73,'0000-00-00 00:00:00',0),(6,'BUY','D',5,73,'0000-00-00 00:00:00',0),(7,'SELL','T',110,37,'0000-00-00 00:00:00',0),(8,'BUY','V',2,82,'0000-00-00 00:00:00',0),(9,'SELL','D',368,74,'0000-00-00 00:00:00',0),(10,'SELL','K',1,74,'2016-10-26 18:40:29',14),(11,'SELL','K',1,74,'2016-10-26 18:41:53',14),(12,'BUY','K',2,74,'2016-10-26 20:06:07',16),(13,'SELL','K',2,74,'2016-10-26 20:07:48',16),(14,'BUY','K',-3,74,'2016-10-26 20:08:16',16),(15,'BUY','K',-5,74,'2016-10-26 20:12:11',16),(16,'BUY','K',-4,74,'2016-10-26 20:15:54',16),(17,'BUY','K',-9,74,'2016-10-26 20:18:54',16),(18,'BUY','K',-6,74,'2016-10-26 20:20:36',16),(19,'BUY','K',-9,74,'2016-10-26 20:20:54',16),(20,'BUY','K',-5,74,'2016-10-26 20:26:14',16),(21,'BUY','H',5,49,'2016-10-26 20:27:57',16),(22,'BUY','L',-8,41,'2016-10-26 20:28:13',16),(23,'BUY','O',-10,61,'2016-10-26 20:28:41',16),(24,'BUY','P',-8,12,'2016-10-26 20:29:50',16),(25,'BUY','L',-9,41,'2016-10-26 20:30:03',16),(26,'BUY','G',-8,24,'2016-10-26 20:31:01',16),(27,'BUY','K',0,74,'2016-10-26 20:36:26',16),(28,'BUY','G',0,24,'2016-10-26 20:36:45',16),(29,'BUY','F',0,12,'2016-10-26 20:37:02',16),(30,'BUY','K',0,74,'2016-10-26 20:40:01',16),(31,'BUY','K',0,74,'2016-10-26 20:40:24',16),(32,'BUY','A',0,43,'2016-10-26 20:40:46',16),(33,'BUY','K',5,74,'2016-10-26 20:41:52',16),(34,'BUY','H',100,49,'2016-10-27 06:46:28',19),(35,'SELL','H',100,49,'2016-10-27 06:52:47',19),(36,'BUY','K',10,74,'2016-10-27 12:04:39',19),(37,'SELL','K',10,74,'2016-10-27 12:42:00',19);
/*!40000 ALTER TABLE `History` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `portfolios`
--

DROP TABLE IF EXISTS `portfolios`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `portfolios` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `user_id` int(10) unsigned NOT NULL,
  `symbol` varchar(255) NOT NULL,
  `shares` int(200) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  UNIQUE KEY `user_id` (`user_id`,`symbol`),
  KEY `user_id_2` (`user_id`),
  CONSTRAINT `portfolios_ibfk_1` FOREIGN KEY (`user_id`) REFERENCES `users` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=60 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `portfolios`
--

LOCK TABLES `portfolios` WRITE;
/*!40000 ALTER TABLE `portfolios` DISABLE KEYS */;
INSERT INTO `portfolios` VALUES (1,3,'NM',5),(11,4,'T',5),(46,16,'o',122),(50,16,'k',5),(57,16,'h',5);
/*!40000 ALTER TABLE `portfolios` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `users`
--

DROP TABLE IF EXISTS `users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `users` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `username` varchar(255) NOT NULL,
  `hash` varchar(255) NOT NULL,
  `cash` decimal(65,3) NOT NULL DEFAULT '0.000',
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`)
) ENGINE=InnoDB AUTO_INCREMENT=20 DEFAULT CHARSET=latin1;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `users`
--

LOCK TABLES `users` WRITE;
/*!40000 ALTER TABLE `users` DISABLE KEYS */;
INSERT INTO `users` VALUES (1,'andi','$2y$10$c.e4DK7pVyLT.stmHxgAleWq4yViMmkwKz3x8XCo4b/u3r8g5OTnS',10000.000),(2,'caesar','$2y$10$0p2dlmu6HnhzEMf9UaUIfuaQP7tFVDMxgFcVs0irhGqhOxt6hJFaa',10000.000),(3,'eli','$2y$10$COO6EnTVrCPCEddZyWeEJeH9qPCwPkCS0jJpusNiru.XpRN6Jf7HW',10000.000),(4,'hdan','$2y$10$o9a4ZoHqVkVHSno6j.k34.wC.qzgeQTBHiwa3rpnLq7j2PlPJHo1G',10000.000),(5,'jason','$2y$10$ci2zwcWLJmSSqyhCnHKUF.AjoysFMvlIb1w4zfmCS7/WaOrmBnLNe',10000.000),(6,'john','$2y$10$dy.LVhWgoxIQHAgfCStWietGdJCPjnNrxKNRs5twGcMrQvAPPIxSy',10000.000),(7,'levatich','$2y$10$fBfk7L/QFiplffZdo6etM.096pt4Oyz2imLSp5s8HUAykdLXaz6MK',10000.000),(8,'rob','$2y$10$3pRWcBbGdAdzdDiVVybKSeFq6C50g80zyPRAxcsh2t5UnwAkG.I.2',10000.000),(9,'skroob','$2y$10$395b7wODm.o2N7W5UZSXXuXwrC0OtFB17w4VjPnCIn/nvv9e4XUQK',10000.000),(10,'zamyla','$2y$10$UOaRF0LGOaeHG4oaEkfO4O7vfI34B1W23WqHr9zCpXL68hfQsS3/e',10000.000),(11,'Ksenia','$2y$10$4GgZNqw3CSaH3lEEZ3l6aeLRM7g2uWt9By5mojOHl3MKTsuXfe9Mq',10000.000),(12,'F','$2y$10$Ua2RLGxFUzBPnp6AKw884OuTHwzG7Q0HNA5F5xQjZBaBM1c9xbAVy',10000.000),(13,'Ivan','$2y$10$p4cU5y5wcP8TM3mZrZyWfu0KkTXOjJiHIh9TZezDaZx785T4X2ShK',10000.000),(14,'Nina','$2y$10$vKgX1vIpyyeBNE4ntbKub.iXC974yvkF1nQTpsVcBy/YUh3oeNdxC',9067.582),(15,'Lily','$2y$10$X4Wmr78wMcLsv61Ckl0j..YcpSf4bYvjKUObTjxKcQO6VPYbPPmMq',10000.000),(16,'Mila','$2y$10$UGe1VAwdrMoCaMIu6yoI.uoBKkJxQ2chZqpc5.GdWZ4aA0bci8y1K',5919.155),(17,'Peter','$2y$10$9uLXgu9W9Y3WYVOvQQd6IeQ8vz9aU5R.xea5ZSIJeOhWxNx3bzC3u',10000.000),(18,'Peter1','$2y$10$XbFxhGd9ALLWlVHVBOiXBukAP4q7kQyidWlssZXQGcvmO2S28aYJa',10000.000),(19,'k','$2y$10$wz4z3kEJgy3gUjIXOrayv.XbDrK5uyyo6KqdmbncSbryPNJ33/uVK',5137.000);
/*!40000 ALTER TABLE `users` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2016-10-27 14:11:27
