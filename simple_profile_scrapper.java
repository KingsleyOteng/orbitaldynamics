package simple_profile_scrapper;
import java.util.regex.*; 
import java.io.IOException;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

/**
 * @title       simple load profile web scrapper
 * @author      kwadwo oteng-amoako, 19 November, 2020
 * @contact     k.oteng@ieee.org
 * @started     19 November 2020
 * @status      complete 19 November 2020
 * @lastedit    10 December 2020
 * @description The following routine will scrape an ecg data file and convert it into a CSV format which may be edited through excel
 */
public class simple_profile_scrapper {

    /**
     * @param args the command line arguments
     * @throws java.io.FileNotFoundException
     */

private List<Integer> stack;
private int stack_size;

public static void main(String args[]) throws FileNotFoundException, IOException {
    
        simple_profile_scrapper x = new simple_profile_scrapper();
        x.createStack(4);
        x.push(1);
        x.push(2);
        x.push(3);
        x.push(4);
        System.out.println("here is the mean: " + x.mean() + "\n");
        
  
        //creating File instance to read text file 
        File text = new File("/Users/kwadwooteng-amoko/NetBeansProjects/JavaApplication17/src/simple_profile_scrapper/xcon.txt");
        Scanner scnr = new Scanner(text);
        
    // let us create the pattern matching description
    try ( // creating writer instanc to write text file output
            FileWriter myWriter = new FileWriter("data.csv")) {
        // let us create the pattern matching description
        Pattern ptrn = Pattern.compile("(\\d+-\\d+-\\d+)\\s+(\\d+:\\d+:\\d+)\\s?-\\s?(\\d+:\\d+:\\d+)\\s+GMT\\s+((\\d+,)?\\d+.\\d+)\\s+((\\d+,)?\\d+.\\d+)\\s\\[\\s(\\d+:\\d+:\\d+)\\s+GMT\\s+\\]\\s+(\\d+.\\d+)");
        // counter
        int lineNumber = 1;
        // from scanner loop by line until match is identified, scrape line and write formatted data
        while (scnr.hasNextLine()) {
            // read line
            String line = scnr.nextLine();
            
            // output to terminal
            System.out.println("line " + lineNumber + " :" + line);
            
            // start matcher
            Matcher matcher = ptrn.matcher(line);
            
            // where there is a match, describe the detail of match and write formatted data
            while (matcher.find())
            {
                
                System.out.println(String.format("Matched: %s at index [%d, %d]", matcher.group(), matcher.start(), matcher.end()));
                
                System.out.println(lineNumber+";"+matcher.group(1)+";"+matcher.group(2)+";"+matcher.group(3)+";"+matcher.group(4)+";"+matcher.group(6)+";"+matcher.group(8)+";"+matcher.group(9)+"\n");
                
                myWriter.write("ecg_data"+";"+lineNumber+";"+matcher.group(1)+";"+matcher.group(2)+";"+matcher.group(3)+";"+matcher.group(4)+";"+matcher.group(6)+";"+matcher.group(8)+";"+matcher.group(9)+"\n");
            }
            
            lineNumber++;
        }
        //close file output
    }
    }   

 public void createStack(int SIZE) 
    {
        stack_size = SIZE;
        stack = new ArrayList<Integer>(SIZE);
    }

  public void push(int i) 
    {

       stack.add(0,i);
    }
  
  public int pop() 
    {
        if(!stack.isEmpty())
        {
           int i= stack.get(0);
           stack.remove(0);
           return i;
        } else{
           return -1;// Or any invalid value
        }
    }
  
  public int peek()
     {
        if(!stack.isEmpty()){
           return stack.get(0);
        } else{
           return -1;// Or any invalid value
        }
     }
  
  public double mean()
     {
        if(!stack.isEmpty()){
            
            double summation = 0;
            
            for (int xI = 0;  xI < stack_size; xI++)
            {
                summation = stack.get(xI);
            }
            
           return summation;
        } else{
           return -1;// Or any invalid value
        }
     }
    
};
