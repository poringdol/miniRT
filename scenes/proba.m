
%clc, clear all, close all
% x1=-4; y1=5; z1=6;
% ax=-2; ay=4; az=6;
% X=[x1 ax-x1];
% Y=[y1 ay-y1];
% Z=[z1 az-z1];
% plot3(X,Y,Z)
% set(gca, 'XGrid', 'on', 'YGrid', 'on', 'ZGrid', 'on');

% %��������� ������ (x-x0)/nx=(y-y0)/yx=(z-z0)/nz
% %�������� ����� ����� x0 y0 z0
% x0=0; y0=0; z0=0;
% %�������� ����� ����� x1 y1 z1
% x1=1; y1=1; z1=1;
% plot3([x0 x1-x0],[y0 y1-y0],[z0 z1-z0]);
% set(gca, 'XGrid', 'on', 'YGrid', 'on', 'ZGrid', 'on');
% hold on
% 
%��������� ������ (x-x0)/nx=(y-y0)/yx=(z-z0)/nz
%�������� ����� ����� x0 y0 z0
x0=5; y0=0; z0=0;
%�������� ����� ����� x1 y1 z1
x1=60; y1=10; z1=10;
p1=plot3([x0 x1-x0],[y0 y1-y0],[z0 z1-z0]);
set(gca, 'XGrid', 'on', 'YGrid', 'on', 'ZGrid', 'on');
set(p1,'Color','r');
set(p1,'LineWidth',3);
hold on

%�����
%���������� ������
x0=40; y0=40; z0=40;
%������
r=20;
[x,y,z]=sphere(50);
s1=surf(x*r+x0,y*r+y0,z*r+z0);
set(s1,'EdgeColor','k');
set(s1,'FaceColor','r');
axis equal
clear x0 y0 z0 r x y z
%���������� ������
% xk=0; yk=0; zk=0;
% %���� ������ ������ 
% alpaha_k=60;
% %������������ ������ ������
% nkx=1; nky=1; nkz=1;

%�����
%���������� ������
x0=15; y0=20; z0=20;
%������
r=5;
[x,y,z]=sphere(50);
s1=surf(x*r+x0,y*r+y0,z*r+z0);
set(s1,'EdgeColor','k');
set(s1,'FaceColor','g');
axis equal
clear x0 y0 z0 r x y z
%���������� ������
% xk=0; yk=0; zk=0;
% %���� ������ ������ 
% alpaha_k=60;
% %������������ ������ ������
% nkx=1; nky=1; nkz=1;


%�����
%���������� ������
x0=20; y0=20; z0=20;
%������
r=5;
[x,y,z]=sphere(50);
s1=surf(x*r+x0,y*r+y0,z*r+z0);
set(s1,'EdgeColor','k');
set(s1,'FaceColor','b');
axis equal
clear x0 y0 z0 r x y z
%���������� ������
% xk=0; yk=0; zk=0;
% %���� ������ ������ 
% alpaha_k=60;
% %������������ ������ ������
% nkx=1; nky=1; nkz=1;
