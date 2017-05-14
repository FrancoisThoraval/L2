1)

create table EMPLACEMENT (
	NOEMP number(5) not null,
	TYPE varchar(50),
	SUPERF num(50),
	PRIX number(10),
	CODCAMP varchar(5),
	
	constraint pk_emp primary key (NOEMP),
	constraint fk_camp foreign key (CODCAMP) references CAMPING
);

create table CAMPING (
	CODCAMP varchar(5) not null,
	NOMCAMP varchar(50),
	VILLECAMP varchar(50),
	
	constraint pk_camp primary key (CODCAMP)
);

create table RESERVATION (
	NORESERV number(5) not null,
	DATEDEB date,
	DATEFIN date,
	NOEMP number(5),
	CODCLI varchar(5),

	constraint pk_res primary key (NORESERV),
	constraint fk_cli foreign key (CODCLI)
);

create table CLIENT (
	CODCLI varchar(5) not null,
	NOMCLI varchar(50),
	PRENOMCLI varchar(50),
	ADRESSE varchar(50),
	VILLECLI varchar(50),

	constraint pk_cli primary key (CODCLI)
);
	

3)

select c.villecli 
from CLIENT c, reservation r
where (r.datefin - r.datedeb) > 14
	and r.codcli = c.codcli;

select c.nomcli, c.prenomcli
from client c, reservation r
where r.datefin = (select MAX(r1.datefin) from reservation r1)
	and c.codecli = r.codecli;
	
select ca.codcamp, ca.nomcamp, ca.villecamp
from camping ca
where (select count(distinct e.noemp)
	from emplacement e
	where ca.codcamp = e.codcamp)
	>
	(select count(distinct e2.noemp)
	from camping ca2, emplacement e2 	
	where ca2.nomcamp = 'beau rivage'
		and e2.codcamp = ca2.codcamp);

