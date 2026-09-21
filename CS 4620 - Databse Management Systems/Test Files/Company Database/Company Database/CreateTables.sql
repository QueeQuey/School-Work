-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema mydb
-- -----------------------------------------------------
-- -----------------------------------------------------
-- Schema aheydar
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema aheydar
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `aheydar` DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci ;
USE `aheydar` ;

-- -----------------------------------------------------
-- Table `aheydar`.`EMPLOYEE`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `aheydar`.`EMPLOYEE` (
  `Fname` VARCHAR(15) NOT NULL,
  `Minit` CHAR(1) NULL DEFAULT NULL,
  `Lname` VARCHAR(15) NOT NULL,
  `Ssn` CHAR(9) NOT NULL,
  `Bdate` DATE NULL DEFAULT NULL,
  `Address` VARCHAR(30) NULL DEFAULT NULL,
  `Sex` CHAR(1) NULL DEFAULT NULL,
  `Salary` DECIMAL(10,2) NULL DEFAULT NULL,
  `Super_ssn` CHAR(9) NULL DEFAULT NULL,
  `Dno` INT NOT NULL,
  PRIMARY KEY (`Ssn`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8mb4
COLLATE = utf8mb4_0900_ai_ci;


-- -----------------------------------------------------
-- Table `aheydar`.`DEPARTMENT`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `aheydar`.`DEPARTMENT` (
  `Dname` VARCHAR(15) NOT NULL,
  `Dnumber` INT NOT NULL,
  `Mgr_ssn` CHAR(9) NOT NULL,
  `Mgr_start_date` DATE NULL DEFAULT NULL,
  PRIMARY KEY (`Dnumber`),
  UNIQUE INDEX `Dname_UNIQUE` (`Dname` ASC) VISIBLE,
  INDEX `Mgr_ssn` (`Mgr_ssn` ASC) VISIBLE,
  CONSTRAINT `DEPARTMENT_ibfk_1`
    FOREIGN KEY (`Mgr_ssn`)
    REFERENCES `aheydar`.`EMPLOYEE` (`Ssn`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8mb4
COLLATE = utf8mb4_0900_ai_ci;


-- -----------------------------------------------------
-- Table `aheydar`.`DEPENDENT`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `aheydar`.`DEPENDENT` (
  `Essn` CHAR(9) NOT NULL,
  `Dependent_name` VARCHAR(15) NOT NULL,
  `Sex` CHAR(1) NULL DEFAULT NULL,
  `Bdate` DATE NULL DEFAULT NULL,
  `Relationship` VARCHAR(8) NULL DEFAULT NULL,
  PRIMARY KEY (`Essn`, `Dependent_name`),
  CONSTRAINT `DEPENDENT_ibfk_1`
    FOREIGN KEY (`Essn`)
    REFERENCES `aheydar`.`EMPLOYEE` (`Ssn`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8mb4
COLLATE = utf8mb4_0900_ai_ci;


-- -----------------------------------------------------
-- Table `aheydar`.`DEPT_LOCATIONS`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `aheydar`.`DEPT_LOCATIONS` (
  `Dnumber` INT NOT NULL,
  `Dlocation` VARCHAR(15) NOT NULL,
  PRIMARY KEY (`Dnumber`, `Dlocation`),
  CONSTRAINT `DEPT_LOCATIONS_ibfk_1`
    FOREIGN KEY (`Dnumber`)
    REFERENCES `aheydar`.`DEPARTMENT` (`Dnumber`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8mb4
COLLATE = utf8mb4_0900_ai_ci;


-- -----------------------------------------------------
-- Table `aheydar`.`PROJECT`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `aheydar`.`PROJECT` (
  `Pname` VARCHAR(15) NOT NULL,
  `Pnumber` INT NOT NULL,
  `Plocation` VARCHAR(15) NULL DEFAULT NULL,
  `Dnum` INT NULL DEFAULT NULL,
  PRIMARY KEY (`Pnumber`),
  UNIQUE INDEX `Pname_UNIQUE` (`Pname` ASC) VISIBLE,
  INDEX `Dnum` (`Dnum` ASC) VISIBLE,
  CONSTRAINT `PROJECT_ibfk_1`
    FOREIGN KEY (`Dnum`)
    REFERENCES `aheydar`.`DEPARTMENT` (`Dnumber`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8mb4
COLLATE = utf8mb4_0900_ai_ci;


-- -----------------------------------------------------
-- Table `aheydar`.`WORKS_ON`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `aheydar`.`WORKS_ON` (
  `Essn` CHAR(9) NOT NULL,
  `Pno` INT NOT NULL,
  `Hours` DECIMAL(3,1) NOT NULL,
  PRIMARY KEY (`Essn`, `Pno`),
  INDEX `Pno` (`Pno` ASC) VISIBLE,
  CONSTRAINT `WORKS_ON_ibfk_1`
    FOREIGN KEY (`Essn`)
    REFERENCES `aheydar`.`EMPLOYEE` (`Ssn`),
  CONSTRAINT `WORKS_ON_ibfk_2`
    FOREIGN KEY (`Pno`)
    REFERENCES `aheydar`.`PROJECT` (`Pnumber`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8mb4
COLLATE = utf8mb4_0900_ai_ci;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
