-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema mydb
-- -----------------------------------------------------
-- -----------------------------------------------------
-- Schema stadiumdb
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema stadiumdb
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `stadiumdb` DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci ;
USE `stadiumdb` ;

-- -----------------------------------------------------
-- Table `stadiumdb`.`venue`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `stadiumdb`.`venue` (
  `venue_id` CHAR(5) NOT NULL,
  `venue_name` VARCHAR(30) NULL DEFAULT NULL,
  PRIMARY KEY (`venue_id`))
ENGINE = InnoDB
AUTO_INCREMENT = 11
DEFAULT CHARACTER SET = utf8mb4
COLLATE = utf8mb4_0900_ai_ci;


-- -----------------------------------------------------
-- Table `stadiumdb`.`match`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `stadiumdb`.`match` (
  `match_id` CHAR(5) NOT NULL,
  `venue_venue_id` CHAR(5) NOT NULL,
  `match_kind` ENUM('Football', 'Soccer', 'Hockey', 'Baseball', 'Basketball', 'Tennis') NULL DEFAULT NULL,
  `match_date` DATE NULL,
  `match_time` TIME NULL,
  PRIMARY KEY (`match_id`),
  INDEX `fk_match_venue1_idx` (`venue_venue_id` ASC) VISIBLE,
  CONSTRAINT `fk_match_venue1`
    FOREIGN KEY (`venue_venue_id`)
    REFERENCES `stadiumdb`.`venue` (`venue_id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
AUTO_INCREMENT = 11
DEFAULT CHARACTER SET = utf8mb4
COLLATE = utf8mb4_0900_ai_ci;


-- -----------------------------------------------------
-- Table `stadiumdb`.`user`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `stadiumdb`.`user` (
  `user_id` CHAR(5) NOT NULL,
  `first_name` VARCHAR(30) NOT NULL,
  `last_name` VARCHAR(30) NOT NULL,
  `phone_number` VARCHAR(12) NOT NULL,
  `email` VARCHAR(50) NULL DEFAULT NULL,
  `gender` ENUM('MALE', 'FEMALE') NULL DEFAULT NULL,
  `verified` TINYINT NULL DEFAULT NULL,
  PRIMARY KEY (`user_id`))
ENGINE = InnoDB
AUTO_INCREMENT = 7
DEFAULT CHARACTER SET = utf8mb4
COLLATE = utf8mb4_0900_ai_ci;


-- -----------------------------------------------------
-- Table `stadiumdb`.`ticket`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `stadiumdb`.`ticket` (
  `ticket_id` CHAR(5) NOT NULL,
  `match_match_id` CHAR(5) NOT NULL,
  `type` ENUM('NORMAL', 'VIP') NULL DEFAULT 'NORMAL',
  `seat_id` INT NULL DEFAULT NULL,
  `price` INT NULL DEFAULT 0,
  PRIMARY KEY (`ticket_id`),
  INDEX `fk_ticket_match1_idx` (`match_match_id` ASC) VISIBLE,
  CONSTRAINT `fk_ticket_match1`
    FOREIGN KEY (`match_match_id`)
    REFERENCES `stadiumdb`.`match` (`match_id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
AUTO_INCREMENT = 43
DEFAULT CHARACTER SET = utf8mb4
COLLATE = utf8mb4_0900_ai_ci;


-- -----------------------------------------------------
-- Table `stadiumdb`.`purchase`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `stadiumdb`.`purchase` (
  `purchase_id` CHAR(5) NOT NULL,
  `user_user_id` CHAR(5) NOT NULL,
  `ticket_ticket_id` CHAR(5) NOT NULL,
  `purchase_date` DATE NULL DEFAULT NULL,
  PRIMARY KEY (`purchase_id`),
  INDEX `fk_purchase_user1_idx` (`user_user_id` ASC) VISIBLE,
  INDEX `fk_purchase_ticket1_idx` (`ticket_ticket_id` ASC) VISIBLE,
  UNIQUE INDEX `ticket_ticket_id_UNIQUE` (`ticket_ticket_id` ASC) VISIBLE,
  CONSTRAINT `fk_purchase_user1`
    FOREIGN KEY (`user_user_id`)
    REFERENCES `stadiumdb`.`user` (`user_id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_purchase_ticket1`
    FOREIGN KEY (`ticket_ticket_id`)
    REFERENCES `stadiumdb`.`ticket` (`ticket_id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
AUTO_INCREMENT = 32
DEFAULT CHARACTER SET = utf8mb4
COLLATE = utf8mb4_0900_ai_ci;


-- -----------------------------------------------------
-- Table `stadiumdb`.`reservation`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `stadiumdb`.`reservation` (
  `reservation_id` CHAR(5) NOT NULL,
  `user_user_id` CHAR(5) NOT NULL,
  `ticket_ticket_id` CHAR(5) NOT NULL,
  `reservation_date` DATE NULL,
  `status` ENUM('Cancel', 'Deposit', 'Check Out') NULL DEFAULT 'DEPOSIT',
  PRIMARY KEY (`reservation_id`),
  INDEX `fk_reservation_user_idx` (`user_user_id` ASC) VISIBLE,
  INDEX `fk_reservation_ticket1_idx` (`ticket_ticket_id` ASC) VISIBLE,
  UNIQUE INDEX `ticket_ticket_id_UNIQUE` (`ticket_ticket_id` ASC) VISIBLE,
  CONSTRAINT `fk_reservation_user`
    FOREIGN KEY (`user_user_id`)
    REFERENCES `stadiumdb`.`user` (`user_id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_reservation_ticket1`
    FOREIGN KEY (`ticket_ticket_id`)
    REFERENCES `stadiumdb`.`ticket` (`ticket_id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
AUTO_INCREMENT = 14
DEFAULT CHARACTER SET = utf8mb4
COLLATE = utf8mb4_0900_ai_ci;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
