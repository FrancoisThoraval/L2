GISEMENTS: _code, nom, montantresinit, montantresrest, montantprod, zoneGeo, (_codePays),
PAYS: _code, nom,
SOCIETE: _numero, nom, (_codePays),






create table PAYS(
	CODPAYS char(4),
	NOMPAYS varchar(50),

	constraint pk_pays primary key (CODPAYS)
);

create table GISEMENTS(
    CODGIS  char(4),
    CODPAYS char(4),
    SITGEOGRAPHIQUE varchar(50),
    NOMGIS  varchar(50),
    RESERVINIT  number(5), 	-- Gbbl
    RESERVREST  number(5), 	-- Gbbl
    PRODUCTJOUR number(5),	-- Kbbl

    constraint pk_gisements primary key (CODGIS),
    constraint fk_pays foreign key (CODPAYS) references PAYS
);

create table SOCIETE(
	CODSOC char(4),
	CODPAYS char(4),
	NOMSOC varchar(50),

	constraint pk_societe primary key (CODSOC),
	constraint fk_pays2soc foreign key (CODPAYS) references PAYS
);

create table PUITS(
	NPUITS number(4),
	CODSOC char(4),
	CODGIS char(4),
	DATEDEBEXPL date,
	DATEFINEXPL date,

	constraint pk_puits primary key (NPUITS),
	constraint fk_societe foreign key (CODSOC) references SOCIETE,
	constraint fk_gisements foreign key (CODGIS) references GISEMENTS
);

create table HISTEXPLOIT(
	DATEJ date,
	NPUITS number(4),
	VOLPROD number(5),

	constraint pk_histexploit primary key (DATEJ,NPUITS),
	constraint fk_puits foreign key (NPUITS) references PUITS
);

insert into pays values ('0001', 'france');
insert into pays values ('0002', 'canada');
insert into pays values ('0003', 'arabie saoudite');
insert into pays values ('0004', 'italie');
insert into pays values ('0005', 'espagne');
insert into pays values ('0006', 'mexique');

insert into GISEMENTS values ('1001','0001','biscarrosse','gisBisca', 500, 300, 5000);
insert into GISEMENTS values ('1002','0003','arabiland','gisArabiland', 5000, 3000, 90000);
insert into GISEMENTS values ('1003','0004','napoli','terronLand', 500, 3, 50000);
insert into GISEMENTS values ('1008','0004','roma','terronLand', 500, 3, 70000);
insert into GISEMENTS values ('1004','0005','sevilla','olé', 500, 2, 50000);
insert into GISEMENTS values ('1005','0002','monréal','québec', 500, 6, 50000);
insert into GISEMENTS values ('1006','0002','iglou','québec', 500, 35, 50000);
insert into GISEMENTS values ('1007','0006','golfe du mexique','chupaxa', 500, 35, 50000);

insert into SOCIETE values ('2001', '0001','Pétrole de l''ouest');
insert into SOCIETE values ('2006', '0002','tabernac');
insert into SOCIETE values ('2002', '0004','agip');
insert into SOCIETE values ('2003', '0003','vitriol');
insert into SOCIETE values ('2004', '0005','el petrolito');
insert into SOCIETE values ('2005', '0003','chinaNumbaWan');

insert into PUITS values (1,'2001','1001','01-JANUARY-1990','11-MARCH-2005');
insert into PUITS values (2,'2006','1001','01-JANUARY-1991','11-MARCH-2006');
insert into PUITS values (3,'2002','1001','01-JANUARY-1999','11-MARCH-2008');
insert into PUITS values (4,'2003','1002','01-JANUARY-1998','11-MARCH-2010');
insert into PUITS values (5,'2004','1003','01-JANUARY-2003','11-MARCH-2020');
insert into PUITS values (6,'2005','1004','01-JANUARY-2000','11-MARCH-2035');
insert into PUITS values (7,'2005','1004','01-JANUARY-2012','11-MARCH-2015');
insert into PUITS values (8,'2005','1004','01-JANUARY-2007','11-MARCH-2036');
insert into PUITS values (9,'2006','1006','01-JANUARY-2005','11-MARCH-2019');
insert into PUITS values (10,'2006','1006','01-JANUARY-2015','11-MARCH-2019');
	-- puits Golfe du Méxique
insert into PUITS values (11,'2006','1007','01-JANUARY-2015','11-MARCH-2019');
insert into PUITS values (12,'2006','1007','01-JANUARY-2015','11-MARCH-2019');
insert into PUITS values (13,'2006','1007','01-JANUARY-2015','11-MARCH-2019');
insert into PUITS values (14,'2005','1007','01-JANUARY-2015','11-MARCH-2019');
insert into PUITS values (15,'2005','1007','01-JANUARY-2015','11-MARCH-2019');


insert into HISTEXPLOIT values ('01-JANUARY-2009',1,2000);
insert into HISTEXPLOIT values ('01-JANUARY-2009',2,2000);
insert into HISTEXPLOIT values ('01-JANUARY-2009',3,2000);
insert into HISTEXPLOIT values ('01-JANUARY-2009',4,2000);
insert into HISTEXPLOIT values ('01-JANUARY-2009',6,2000);
insert into HISTEXPLOIT values ('01-JANUARY-2009',7,2000);
insert into HISTEXPLOIT values ('01-JANUARY-2009',8,2000);
insert into HISTEXPLOIT values ('01-JANUARY-2009',9,2000);
insert into HISTEXPLOIT values ('01-JANUARY-2010',1,2000);


-- Q1
select CODGIS,NOMGIS from GISEMENTS g, PAYS p
where(	g.RESERVINIT > 20
		and p.NOMPAYS = 'canada'
		and p.CODPAYS = g.CODPAYS
);

-- Q2
select CODSOC, NOMSOC from SOCIETE s
minus(select CODSOC, NOMSOC from SOCIETE s, PAYS p
	where(p.NOMPAYS = 'arabie saoudite'
		and s.CODPAYS = p.CODPAYS
	)
);

-- Q3

--Version Legit
select g.CODGIS, NOMGIS
FROM GISEMENTS g, PUITS p
WHERE (g.CODGIS = p.CODGIS
	AND p.DATEDEBEXPL > (select DATEFINEXPL from puits p2
				where(p2.NPUITS = 3)
				)
	)

--Soluce cheatée

SELECT g.codgis, g.NOMGIS FROM gisements g,puits p
LEFT JOIN puits p2
ON p.datedebexpl > p2.datefinexpl WHERE p2.npuits = 3
and p.codgis = g.codgis

-- Q4

SELECT NOMSOC
FROM SOCIETE s, GISEMENTS g
WHERE s.CODPAYS=g.CODPAYS
GROUP BY s.CODPAYS, NOMSOC
HAVING COUNT(g.CODPAYS)>=2;

-- Q5

select CODPAYS, NOMPAYS, g.RESERVREST
from PAYS p , GISEMENTS g
where(p.CODPAYS = g.CODPAYS
	and g.RESERVREST < 4)

-- Q6
select s.CODSOC, s.NOMSOC
from SOCIETE s, gisements g, puits p
where(g.SITGEOGRAPHIQUE = 'golfe du mexique'
	and p.CODGIS = g.codgis
	and p.CODSOC = s.CODSOC)
GROUP by s.codsoc, s.NOMSOC
HAVING count(s.codsoc)=(select max(count(s.codsoc) from SOCIETE s))

SELECT s.codsoc, s.NOMSOC
FROM SOCIETE s, gisements g, puits p
WHERE s.codsoc=p.codsoc and p.codgis = g.codgis and g.SITGEOGRAPHIQUE = 'golfe du mexique'
GROUP BY s.codsoc, s.NOMSOC
HAVING MAX(COUNT(p.codsoc))
