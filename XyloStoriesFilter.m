function out = XyloStoriesFilter(inputData)
    %out = zeros(8,1);
    out = 0;
    
    %C1
    bandpass = fir1(48,[0.4 0.42]);
    band = filter(bandpass,1,inputData);
    for i = 1:length(band)
        if band(i,1) >= 30
            %out(1,1) = 1;
            out = 1;
        end
    end
    
    %D
    bandpass = fir1(48,[0.44 0.5]);
    band = filter(bandpass,1,inputData);
    for i = 1:length(band)
        if band(i,1) >= 30
            %out(2,1) = 2;
            out = 2;
        end
    end
    
    
    %E
    bandpass = fir1(48,[0.51 0.54]);
    band = filter(bandpass,1,inputData);
    for i = 1:length(band)
        if band(i,1) >= 30
            %out(3,1) = 3;
            out = 3;
        end
    end
    
    %F
    bandpass = fir1(48,[0.55 0.58]);
    band = filter(bandpass,1,inputData);
    for i = 1:length(band)
        if band(i,1) >= 30
            %out(4,1) = 4;
            out = 4;
        end
    end
    
    %G
    bandpass = fir1(48,[0.6 0.64]);
    band = filter(bandpass,1,inputData);
    for i = 1:length(band)
        if band(i,1) >= 30
            %out(5,1) = 5;
            out = 5;
        end
    end
    
    %A
    bandpass = fir1(48,[0.68 0.72]);
    band = filter(bandpass,1,inputData);
    for i = 1:length(band)
        if band(i,1) >= 30
            %out(6,1) = 6;
            out = 6;
        end
    end
    
    %B
    bandpass = fir1(48,[0.76 0.8]);
    band = filter(bandpass,1,inputData);
    for i = 1:length(band)
        if band(i,1) >= 30
            %out(7,1) = 7;
            out = 7;
        end
    end
    
    %C2
    bandpass = fir1(48,[0.82 0.84]);
    band = filter(bandpass,1,inputData);
    for i = 1:length(band)
        if band(i,1) >= 30
            %out(8,1) = 8;
            out = 8;
        end
    end
    
end