use test;
show tables;
create table if not exists face_img(
   img_id INT UNSIGNED AUTO_INCREMENT,
   img_name varchar(100) not null,
   gender varchar(40) default null,
   smile varchar(40) default null,
   primary key  (img_id)
)engine=InnoDB default charset=utf8;
-- insert into face_img (img_name,gender,smile) values ('zhaowei.jpg','male','yes');
-- insert into face_img (img_name,gender,smile) values ('jiayi.jpg','male','no');
-- insert into face_img (img_name,gender,smile) values ('wyp.jpg','female','no');
-- insert into face_img (img_name,gender,smile) values ('liupei.jpg','female','yes');
select * from face_img where gender = 'male';
