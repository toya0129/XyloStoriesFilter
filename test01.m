while(1)
    i=0;
    for i = 1:400 
        b(i,1) = testD(j,1); 
        j =j+1; 
    end
    
    a = [a;XyloStoriesFilter(b)];
    
%     if a ~= 1
%         break;
%     end
    
    %if i >= 20000
        break;
    %end
    
    k=k+1;
        

end
