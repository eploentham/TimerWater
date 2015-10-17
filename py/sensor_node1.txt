CREATE TABLE t_device (id varchar(255), device_id varchar(255), device_type varchar(255), date_device varchar(255), value1 varchar(255), unit1 varchar(255), remark varchar(255), PRIMARY KEY (id));
CREATE TABLE t_sensor (id varchar(255), device_id varchar(255), device_type varchar(255), date_device varchar(255)
	, distance1 varchar(255), soil1 varchar(255), temperature1 varchar(255)
	, distance2 varchar(255), soil2 varchar(255), temperature2 varchar(255)
	, distance3 varchar(255), soil3 varchar(255), temperature3 varchar(255)
	, distance4 varchar(255), soil4 varchar(255), temperature4 varchar(255)
	, distance5 varchar(255), soil5 varchar(255), temperature5 varchar(255)
	, d_unit1 varchar(255), s_unit1 varchar(255), t_unit1 varchar(255)
	, d_unit2 varchar(255), s_unit2 varchar(255), t_unit2 varchar(255)
	, d_unit3 varchar(255), s_unit3 varchar(255), t_unit3 varchar(255)
	, d_unit4 varchar(255), s_unit4 varchar(255), t_unit4 varchar(255)
	, d_unit5 varchar(255), s_unit5 varchar(255), t_unit5 varchar(255)
	, remark varchar(255), PRIMARY KEY (id));