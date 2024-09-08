clc
close all 
clear

% DATA READING FROM CSV AND .MAT FILES 
anchors=readtable('anchorsUT.csv'); 
load('workstation_pos.mat'); 


% IMAGE IMPORT 
I=imread('NH_cleanup.jpg');


% Image dimensions 

xlim=[0 11.35]; 
ylim=[0 6.11];
h=image(xlim,ylim,I);
uistack(h,'bottom');
hold on 

% PLOTTING THE WORKSTATIONS USING POLYSHAPE
% polyshape([X-DIMENSIONS],[Y-DIMENSION]);

pgon(1,1)=polyshape([workstation_pos{1,5}+0.52 workstation_pos{1,5}+0.52 workstation_pos{1,5}-0.52 workstation_pos{1,5}-0.52 ],[workstation_pos{1,6} workstation_pos{1,6}-0.67 workstation_pos{1,6}-0.67 workstation_pos{1,6}]); 
pgon(1,2)= polyshape([workstation_pos{2,5}+0.52 workstation_pos{2,5} workstation_pos{2,5} workstation_pos{2,5}+0.52 ],[workstation_pos{2,6}-0.67 workstation_pos{2,6}-0.67 workstation_pos{2,6}+0.67 workstation_pos{2,6}+0.67]); 
pgon(1,3)=polyshape([workstation_pos{3,5}+0.52 workstation_pos{3,5} workstation_pos{3,5} workstation_pos{3,5}+0.52 ],[workstation_pos{3,6}-0.67 workstation_pos{3,6}-0.67 workstation_pos{3,6}+0.67 workstation_pos{3,6}+0.67]);
pgon(1,4)=polyshape([workstation_pos{4,5}+0.52 workstation_pos{4,5} workstation_pos{4,5} workstation_pos{4,5}+0.52 ],[workstation_pos{4,6}-0.67 workstation_pos{4,6}-0.67 workstation_pos{4,6}+0.67 workstation_pos{4,6}+0.67]);
pgon(1,5)=polyshape([workstation_pos{5,5}-0.52 workstation_pos{5,5}-0.52 workstation_pos{5,5}+0.52 workstation_pos{5,5}+0.52 ],[workstation_pos{5,6} workstation_pos{5,6}+0.67 workstation_pos{5,6}+0.67 workstation_pos{5,6}]);
pgon(1,6)=polyshape([workstation_pos{6,5}-0.52 workstation_pos{6,5}-0.52 workstation_pos{6,5}+0.52 workstation_pos{6,5}+0.52 ],[workstation_pos{5,6} workstation_pos{5,6}+0.67 workstation_pos{5,6}+0.67 workstation_pos{5,6}]);

plot(pgon,"LineWidth",2,"FaceColor","k","EdgeColor","k"); 

hold on 

% storage location : to be done on your own 
% X = 3.209
% Y= 4.842


% UWB TAGS ON WS 

scatter(workstation_pos{1:5,5},workstation_pos{1:5,6},100,'filled','MarkerFaceColor','green','MarkerEdgeColor','red'); 
hold on 
scatter(workstation_pos{6,5},workstation_pos{5,6},100,'filled','MarkerFaceColor','green','MarkerEdgeColor','red'); 
hold on 
scatter(workstation_pos{1,5},workstation_pos{1,6}-0.67,100,'filled','MarkerFaceColor','green','MarkerEdgeColor','red');
hold on 
scatter(workstation_pos{2,5}+0.52,workstation_pos{2,6},100,'filled','MarkerFaceColor','green','MarkerEdgeColor','red');
hold on 
scatter(workstation_pos{3,5}+0.52,workstation_pos{3,6},100,'filled','MarkerFaceColor','green','MarkerEdgeColor','red');
hold on 
scatter(workstation_pos{4,5}+0.52,workstation_pos{4,6},100,'filled','MarkerFaceColor','green','MarkerEdgeColor','red');
hold on 
scatter(workstation_pos{5,5},workstation_pos{5,6}+0.67,100,'filled','MarkerFaceColor','green','MarkerEdgeColor','red');
hold on 
scatter(workstation_pos{6,5},workstation_pos{5,6}+0.67,100,'filled','MarkerFaceColor','green','MarkerEdgeColor','red');


% ANCHORS TO BE ADDED

for i=1:size(anchors,1)
    scatter(anchors{i,3},anchors{i,4},200,'h','filled','MarkerFaceColor','b','MarkerEdgeColor','m');
    hold on 

end 

% Plotting strings in each workstation 


for i=1:size(workstation_pos,1)

    str=string(i); 
    text(workstation_pos{i,5},workstation_pos{i,6},str,'Color','k','FontSize',20); 

end 


% Include 5 operators 

% 2 operators in front of station 1 
% 1 in front of WS2
% 1 in front of WS3
% 1 in front of WS4

% MAKE SURE TO MODIFY YOUR LEGEND ACCORDINGLY!!



% AXIS labels 

xlabel('X-axis (m)','Fontsize',18)
xlabel('X-axis (m)','Fontsize',18)

% to increase the ticks on your plot for both axes 
ax=gca; 
ax.FontSize=18; 





legend('WS','','','','','','WS Tag','','','','','','','','','','AN')







