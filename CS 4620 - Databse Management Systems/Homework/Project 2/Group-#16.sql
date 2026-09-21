-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema mydb
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema mydb
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `mydb` DEFAULT CHARACTER SET utf8 ;
USE `mydb` ;

-- -----------------------------------------------------
-- Table `mydb`.`User`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`User` (
  `idUser` INT NULL,
  `Email` VARCHAR(45) NULL,
  `Phone Number` VARCHAR(45) NULL,
  `Password` VARCHAR(45) NULL,
  `Gender` VARCHAR(45) NULL,
  `Verified` TINYINT NOT NULL,
  `First Name` VARCHAR(45) NOT NULL,
  `Last Name` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`idUser`, `Email`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Stadium`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Stadium` (
  `idStadium` INT NOT NULL,
  `nameStadium` VARCHAR(45) NULL,
  `city` VARCHAR(45) NULL,
  `address` VARCHAR(45) NULL,
  PRIMARY KEY (`idStadium`, `nameStadium`),
  UNIQUE INDEX `idStadium_UNIQUE` (`idStadium` ASC) VISIBLE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Sports Venue`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Sports Venue` (
  `idSports Venue` INT NULL,
  `numberOfSeats` INT NULL,
  `sportType` VARCHAR(45) NULL,
  `stadiumId` INT NULL,
  PRIMARY KEY (`idSports Venue`, `stadiumId`),
  INDEX `VENUE_stadiumId_idx` (`stadiumId` ASC) VISIBLE,
  CONSTRAINT `VENUE_stadiumId`
    FOREIGN KEY (`stadiumId`)
    REFERENCES `mydb`.`Stadium` (`idStadium`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Match`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Match` (
  `idMatch` INT NULL,
  `SportType` VARCHAR(45) NULL,
  `Date` DATE NULL,
  `Hour` TIME NULL,
  `Sports Venue_idSports Venue` INT NULL,
  `Sports Venue_stadiumId` INT NULL,
  PRIMARY KEY (`idMatch`, `Sports Venue_idSports Venue`, `Sports Venue_stadiumId`),
  INDEX `fk_Match_Sports Venue1_idx` (`Sports Venue_idSports Venue` ASC, `Sports Venue_stadiumId` ASC) VISIBLE,
  CONSTRAINT `fk_Match_Sports Venue1`
    FOREIGN KEY (`Sports Venue_idSports Venue` , `Sports Venue_stadiumId`)
    REFERENCES `mydb`.`Sports Venue` (`idSports Venue` , `stadiumId`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Sports Hall`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Sports Hall` (
  `idSports Hall` INT NULL,
  PRIMARY KEY (`idSports Hall`),
  CONSTRAINT `HALL_idSportsVenue`
    FOREIGN KEY (`idSports Hall`)
    REFERENCES `mydb`.`Sports Venue` (`idSports Venue`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Sports Field`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Sports Field` (
  `idSports Field` INT NULL,
  INDEX `FIELD_id_idx` (`idSports Field` ASC) VISIBLE,
  PRIMARY KEY (`idSports Field`),
  CONSTRAINT `FIELD_id`
    FOREIGN KEY (`idSports Field`)
    REFERENCES `mydb`.`Sports Venue` (`idSports Venue`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Seat`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Seat` (
  `idSeat` INT NULL,
  `Row` VARCHAR(45) NULL,
  `Column` VARCHAR(45) NULL,
  `Type` VARCHAR(45) NULL,
  `venueId` INT NULL,
  PRIMARY KEY (`idSeat`, `venueId`),
  INDEX `SEAT_venueId_idx` (`venueId` ASC) VISIBLE,
  CONSTRAINT `SEAT_venueId`
    FOREIGN KEY (`venueId`)
    REFERENCES `mydb`.`Sports Venue` (`idSports Venue`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Ticket`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Ticket` (
  `idTicket` INT NULL,
  `stateTicket` TINYINT NULL,
  `pricetTicket` DECIMAL(2) NULL,
  `Seat_idSeat` INT NULL,
  `Seat_venueId` INT NULL,
  PRIMARY KEY (`idTicket`, `Seat_idSeat`, `Seat_venueId`),
  INDEX `fk_Ticket_Seat1_idx` (`Seat_idSeat` ASC, `Seat_venueId` ASC) VISIBLE,
  CONSTRAINT `fk_Ticket_Seat1`
    FOREIGN KEY (`Seat_idSeat` , `Seat_venueId`)
    REFERENCES `mydb`.`Seat` (`idSeat` , `venueId`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Annual Ticket`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Annual Ticket` (
  `idAnnual Ticket` INT NULL,
  INDEX `idTicket_idx` (`idAnnual Ticket` ASC) VISIBLE,
  PRIMARY KEY (`idAnnual Ticket`),
  CONSTRAINT `ANNUAL_idTicket`
    FOREIGN KEY (`idAnnual Ticket`)
    REFERENCES `mydb`.`Ticket` (`idTicket`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Season Ticket`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Season Ticket` (
  `idSeason Ticket` INT NULL,
  INDEX `SEASON_idTicket_idx` (`idSeason Ticket` ASC) VISIBLE,
  PRIMARY KEY (`idSeason Ticket`),
  CONSTRAINT `SEASON_idTicket`
    FOREIGN KEY (`idSeason Ticket`)
    REFERENCES `mydb`.`Ticket` (`idTicket`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Match Ticket`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Match Ticket` (
  `idMatch Ticket` INT NULL,
  INDEX `MATCH_idTicket_idx` (`idMatch Ticket` ASC) VISIBLE,
  PRIMARY KEY (`idMatch Ticket`),
  CONSTRAINT `MATCH_idTicket`
    FOREIGN KEY (`idMatch Ticket`)
    REFERENCES `mydb`.`Ticket` (`idTicket`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Reserves`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Reserves` (
  `idCustomer` INT NULL,
  `idTicket` INT NULL,
  `isBought` TINYINT NULL,
  `Date` DATE NULL,
  `Hour` TIME NULL,
  PRIMARY KEY (`idCustomer`, `idTicket`),
  INDEX `RESERVES_TicketID_idx` (`idTicket` ASC) VISIBLE,
  CONSTRAINT `RESERVES_UserID`
    FOREIGN KEY (`idCustomer`)
    REFERENCES `mydb`.`User` (`idUser`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `RESERVES_TicketID`
    FOREIGN KEY (`idTicket`)
    REFERENCES `mydb`.`Ticket` (`idTicket`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Cancels`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Cancels` (
  `idUser` INT NULL,
  `idTicket` INT NULL,
  `Date` DATE NULL,
  `Hour` TIME NULL,
  PRIMARY KEY (`idUser`, `idTicket`),
  INDEX `CANCELS_TicketID_idx` (`idTicket` ASC) VISIBLE,
  CONSTRAINT `CANCELS_UserID`
    FOREIGN KEY (`idUser`)
    REFERENCES `mydb`.`User` (`idUser`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `CANCELS_TicketID`
    FOREIGN KEY (`idTicket`)
    REFERENCES `mydb`.`Ticket` (`idTicket`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`Buys`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`Buys` (
  `idUser` INT NULL,
  `idTicket` INT NULL,
  `Date` DATE NULL,
  `Hour` TIME NULL,
  PRIMARY KEY (`idUser`, `idTicket`),
  INDEX `BUYS_TicketID_idx` (`idTicket` ASC) VISIBLE,
  CONSTRAINT `BUYS_UserID`
    FOREIGN KEY (`idUser`)
    REFERENCES `mydb`.`User` (`idUser`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `BUYS_TicketID`
    FOREIGN KEY (`idTicket`)
    REFERENCES `mydb`.`Ticket` (`idTicket`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `mydb`.`BelongsTo`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `mydb`.`BelongsTo` (
  `Match_idMatch` INT NULL,
  `Match_Sports Venue_idSports Venue` INT NULL,
  `Match_Sports Venue_stadiumId` INT NULL,
  `Ticket_idTicket` INT NULL,
  PRIMARY KEY (`Match_idMatch`, `Match_Sports Venue_idSports Venue`, `Match_Sports Venue_stadiumId`, `Ticket_idTicket`),
  INDEX `fk_Match_has_Ticket_Ticket1_idx` (`Ticket_idTicket` ASC) VISIBLE,
  INDEX `fk_Match_has_Ticket_Match1_idx` (`Match_idMatch` ASC, `Match_Sports Venue_idSports Venue` ASC, `Match_Sports Venue_stadiumId` ASC) VISIBLE,
  CONSTRAINT `fk_Match_has_Ticket_Match1`
    FOREIGN KEY (`Match_idMatch` , `Match_Sports Venue_idSports Venue` , `Match_Sports Venue_stadiumId`)
    REFERENCES `mydb`.`Match` (`idMatch` , `Sports Venue_idSports Venue` , `Sports Venue_stadiumId`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Match_has_Ticket_Ticket1`
    FOREIGN KEY (`Ticket_idTicket`)
    REFERENCES `mydb`.`Ticket` (`idTicket`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
