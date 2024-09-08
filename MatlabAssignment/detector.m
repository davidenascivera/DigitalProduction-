
events=cell(size(data_operator,1),2);


for c=1:size(data_operator,1)

    % Specify in events the operator number

    events{c,2}=data_operator{c,3};

    % Intializing the first column of events

    events{c,1}(:,1)=NaT(1000,1,'Format','dd-MMM-yyyy HH:mm:ss.SSS');  % TS start
    events{c,1}(:,2)=NaT(1000,1,'Format','dd-MMM-yyyy HH:mm:ss.SSS'); % TS end
    events{c,1}=array2table(events{c,1});

    events{c,1}{:,3}=0; % Idx start
    events{c,1}{:,4}=0; % Idx end
    events{c,1}{:,5}=0; % Duration [sec]
    events{c,1}{:,6}=0; % Polygon # (geo) - Label

    events{c,1}.Properties.VariableNames={'Start time', 'End Time', 'Index Start','Index End','Duration [sec]','Polygon'};

    z=1;

    for j=1:size(geo,2)

        Istart=0;
        Iend=0;


        for i=1:size(label_geofencing{c,1},1)

            if i==1 % This is the first time I'm accessing to label_geofencig

                % Which is the first row equal to 1?
                Istart=find(label_geofencing{c,1}(:,j)==1,1,"first");

                if isempty(Istart)
                    disp('This operator was never detected inside the j-th polygon');
                    break % stop looping at this polygon
                end

                events{c,1}{z,1}=data_operator{c,1}{Istart,1};
                events{c,1}{z,3}=Istart;

                % How long the c-th operator is inside the j-th polygon?
                % We are interested in consecutive timestamps

                Iend=find(label_geofencing{c,1}(Istart:end,j)==0,1,"first")+(Istart-1)-1;

                % What should I do if Iend is empty?

                if isempty(Iend)
                    Iend=size(label_geofencing{c,1},1);
                    disp("This operator is always in this WS")
                    events{c,1}{z,2}=data_operator{c,1}{Iend,1}; % Ts end
                    events{c,1}{z,4}=Iend;
                    events{c,1}{z,6}=j;
                    break


                end

                events{c,1}{z,2}=data_operator{c,1}{Iend,1}; % Ts end
                events{c,1}{z,4}=Iend;
                events{c,1}{z,6}=j;
                z=z+1;
            end

            if i>1
                Istart=find(label_geofencing{c,1}(Iend+1:end,j)==1,1,"first")+ Iend;
                if isempty(Istart)
                    disp('This operator was never again detected inside the j-th polygon');
                    break % stop looping at this polygon
                end
                events{c,1}{z,1}=data_operator{c,1}{Istart,1};
                events{c,1}{z,3}=Istart;

                Iend=find(label_geofencing{c,1}(Istart:end,j)==0,1,"first")+ (Istart-1)-1;

                if isempty(Iend)
                    Iend=size(label_geofencing{c,1},1);
                    disp("This operator is always in this WS")
                    events{c,1}{z,2}=data_operator{c,1}{Iend,1}; % Ts end
                    events{c,1}{z,4}=Iend;
                    events{c,1}{z,6}=j;
                    break
                end

                events{c,1}{z,2}=data_operator{c,1}{Iend,1}; % Ts end
                events{c,1}{z,4}=Iend;
                events{c,1}{z,6}=j;
                z=z+1; 

            end


        end

    end
    
    % Here before mining value in positions of the next operator
    % 1- Eliminate unnecessary rows inside events 
    % 2- Calculate duration of events for each operator
    % 3- Order events by occurence time 
    
    % first row containing NaT in the first two columns or a 0 in the 3rd
    idx=find(events{c,1}{:,3}==0);  
    events{c,1}(idx,:)=[];
    
    % Duration of events
    events{c,1}{:,5}=seconds(events{c,1}{:,2}-events{c,1}{:,1});
    
    % Order events by occurence time 
    events{c,1}=sortrows(events{c,1});

end

