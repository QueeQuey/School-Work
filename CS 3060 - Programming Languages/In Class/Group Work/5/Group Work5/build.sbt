ThisBuild / version := "0.1.0-SNAPSHOT"

ThisBuild / scalaVersion := "2.13.15"

libraryDependencies += "org.scala-lang.modules" %% "scala-xml" % "2.3.0"

lazy val root = (project in file("."))
  .settings(
    name := "Group Work4"
  )
