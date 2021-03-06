# Easy Wait Service
This repository contains the service API

### Local Machine Setup

---
### SOFTWARE SETUP
---

### Composer - The PHP Dependency Manager

Install the latest `Composer` version [here](https://getcomposer.org/download/) ( Both Windows | Linux )

### Laravel Framework

Setup the framework [here](https://laravel.com/docs/5.5)

### Server Setup

Setup the software stack,

- Apache: To serve the webpages
- MySQL: Store all the website content, user profiles, comments etc.
- PHP: Website Programming Language

>**Windows** - [WAMP Server](http://www.wampserver.com/en/)

>**Linux** - [LAMP Server](http://howtoubuntu.org/how-to-install-lamp-on-ubuntu)

---
### ENVIRONMENT SETUP
---

Clone and route to the Git Repository using the commands below in the terminal/cmd: -

`git clone https://github.com/Aasish-Agarwal/EasyWaitService.git`

`cd EasyWaitService`

### Database & Schema Setup

Start the MySQL CLI via the following command: -

`mysql --user="your_user_name" --password="your_password"`

In case of misplaced user & password, reset using the procedure mentioned [here](https://in.godaddy.com/help/reset-your-root-mysql-password-linux-17548).

Inside the MySQL CLI, create a schema for the DB for the application. Execute the following queries to achieve so: -

`use information_schema;`

`create schema easywait_schema;`

`exit`

### Key Generation - Unique Local Machine Authorization Token

Also known as the Application Key`(APP_KEY)`, it is unique string of characters identifying the application on a local machine.

To generate the `APP_KEY`, execute the below command: -

`php artisan key:generate`

### .env File Setup

Inside the EasyWaitService directory, create a new text file and copy the contents of `.env.example` ( present in the same directory ) to this new text file.

Update the following fields in this text file: -

	APP_KEY="key_generated_in_previous_step" (ignore if already present)

	DB_DATABASE=easywait_schema

	DB_USERNAME="your_user_name"

	DB_PASSWORD="your_password"

Save this text file as `.env`, the global environment file for the Laravel project.

---
### DATABASE MIGRATIONS
---
Migrations are files which contain a class definition with both an up() and a down() method.

The `up()` method usually contains the shema for the table and is run when the migration is executed to apply changes to the database. 

The `down()` method is run to revert the changes, ie, rollback.

### Generation of Migration Table

The **Migration Table** is a special table in your database to keep track of what migrations have already been executed.
To generate it, execute the following command: -

`php artisan migrate:install`

Once done, migrate all the DB tables for your application using the below command: -

`php artisan migrate`

---
### START THE SERVER
---

Once done with the above steps, start your server using the below command: -

`php artisan serve`

Open the link provided in a suitable browser to access the server.

---