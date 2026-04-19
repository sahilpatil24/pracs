/*
Car(License,model,year)
Accident(report_no,date,location)
*/

use temp;
create table car(
	license int primary key,
    model varchar(20),
    year_of_purchase year
);

create table accident(
	report_no varchar(10) primary key,
    date_of_accident date,
    location varchar(20),
    check(report_no LIKE "AR%")
);

/*
Owns(driver_id,name,License)
Participated(driver_id,License, report_no, damage_amount)
*/
create table owns(
	driver_id varchar(10) primary key,
    dname varchar(20),
    license int,
    foreign key(license) references car(license),
    check(driver_id LIKE "D%")
);

create table participated(
	driver_id varchar(10),
    license int,
    report_no varchar(10) primary key,
    damage_amount bigint,
    foreign key(driver_id) references owns(driver_id),
    foreign key(license) references car(license),
    foreign key(report_no) references accident(report_no),
    check(driver_id LIKE "D%" and report_no LIKE "AR%")
);

#inserting values
#Car(License,model,year)
insert into car(license, model, year_of_purchase) 
values
('01','Honda',2022),
('17','Benz',2024),
('04','Audi',2021),
('02','Toyota',2020);

#Accident(report_no,date,location)
insert into Accident(report_no,date_of_accident,location)
values
('AR1011','2022-03-05','Mumbai'),
('AR1014','2021-12-03','Bangalore'),
('AR1021','2025-08-07','Manipal'),
('AR1022','2020-02-09','Pune');

#Owns(driver_id,name,License)
insert into owns(driver_id,dname,License)
values
('D1','Rick Dawm',17),
('D2','Johnathan',01),
('D3','Shanks',02),
('D4','Sean Kingston',04);

#Participated(driver_id,License, report_no, damage_amount)
insert into participated(driver_id, license, report_no, damage_amount)
values
('D1',17,'AR1011',50000),
('D2',1,'AR1014',20000),
('D3',2,'AR1021',75000),
('D4',4,'AR1022',15000);

#queries
#1) Add a new car to database assume any values for required attributes.
insert into car values('12','Tata',2010);
select * from car;

#2) Find all accidents happened at bandra.
SET SQL_SAFE_UPDATES = 0;
update accident set location = 'bandra' where location = 'Mumbai';
select * from accident where location = 'bandra';

#3) update the damage amount for the car with license no ‘xxyy 1000’ in accident with report number ‘AR2100’ to 1000.
select * from participated;
update participated set damage_amount = 1000 where license = 17 and report_no = 'AR1011';

#4) Find the total damage amount in which car belonging to ‘John’ was involved
#john,car_name,total_damage
select * from car;
select * from owns;
update owns set dname = 'John' where dname = 'Shanks';
select * from participated;

select owns.dname,car.license,car.model,participated.damage_amount from car inner join owns on car.license = owns.license 
inner join participated on participated.license = owns.license where owns.dname = 'John';