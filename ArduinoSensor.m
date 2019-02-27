function [data,time]=ArduinoSensor()
    disp("program start");

    % arduino connection
    global ard;
    ard = arduino('/dev/cu.usbmodem14101','uno');

    configurePin(ard,'A5','AnalogInput')
    configurePin(ard,'D3','DigitalOutput')
    configurePin(ard,'D4','DigitalOutput')
    configurePin(ard,'D5','DigitalOutput')

    % clock
    writeDigitalPin(ard,'D5',1);
    writeDigitalPin(ard,'D4',0);
    writeDigitalPin(ard,'D3',0);

    % bpFilt = designfilt('bandpassfir','FilterOrder',20,'CutoffFrequency1',1000,'CutoffFrequency2',1100,'SampleRate',4000);
    % lpFilt = designfilt('lowpassiir','FilterOrder',6,'PassbandFrequency',0.005,'PassbandRipple',0.2,'SampleRate',2000);

    i=1;
    global mycell;
    mycell = [];

    global state;
    state=false;

    h = animatedline;

    t=timer;
    t.StartFcn = @startProgram;
    t.TimerFcn = @readProgram;
    t.StopFcn = @endProgram;
    t.Period = 0.01;
    t.TasksToExecute = 10000;
    t.ExecutionMode = 'fixedRate';
    start(t);
    tic;

    disp("Read start");
    while(1) %1ïbä‘Ç…60Hz
        if state==true
            data=mycell;
            time=toc;
            break;
        end
%         ReadSensor();
%     
%      Cstate = readVoltage(ard,'A5');
%      mycell = [mycell;Cstate];
%  
%      addpoints(h,i,Cstate);
%      drawnow;   
    end

    % a = timetable(milliseconds(0:length(mycell)-1)',mycell);
    
    function startProgram(~,~)
        disp('prgram Start');
    end

    function readProgram(~,~)
    % Cstate = readVoltage(ard,'A5');
        mycell = [mycell,readVoltage(ard,'A5')];
    end
    function endProgram(~,~)
        state=true;
    end
end


  