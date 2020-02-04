/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javafxapplication3;

import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.LinkedList;

/**
 *
 * @author kwadwooteng-amoko
 */
public class TimeSeriesAnalysis {

    protected LinkedList<BigDecimal> data = new LinkedList<BigDecimal>();
    protected BigDecimal strike = BigDecimal.ZERO;

    public TimeSeriesAnalysis() {
        // this.data = null;
    }

    public void setValue(BigDecimal value) {
        // add to the linked list
        data.add(value);
    }

    public void setStrike(BigDecimal val)
    {
       this.strike = val;
    }
    
    public BigDecimal getStrike()
    {
       return this.strike;
    }

    public BigDecimal getMean() {
        // initial counter
        BigDecimal sum = BigDecimal.ZERO;
        BigDecimal mean;
        BigDecimal count;

        // generate sum
        for (BigDecimal bd : this.data) {
            // sum = data.stream().reduce(BigDecimal.ZERO, (t, v) -> t.add(v));

            sum = data.stream().reduce(BigDecimal.ZERO, BigDecimal::add);
        }

        // populate the mean
        count = new BigDecimal(this.data.size());
        mean = sum.divide(count, 2, RoundingMode.HALF_UP);

        return (mean);
    }

    public BigDecimal getStd() {
        // initial counter
        BigDecimal sum = BigDecimal.ZERO;
        BigDecimal mean = this.getMean();
        BigDecimal count = this.getCount().subtract(BigDecimal.ONE);

        // generate sum
        for (BigDecimal bd : this.data) {
                  sum = data.stream().reduce(BigDecimal.ZERO, BigDecimal::add);
        }
        
        // divide through by the count
        BigDecimal val = sum.divide(count, 2, RoundingMode.HALF_UP);
        
        
        val = this.getSqrt(val);
        
        return val;
    }

    ;
    
    
    public BigDecimal getSqrt(BigDecimal bd) {
        BigDecimal TWO = new BigDecimal(2);
        BigDecimal error = new BigDecimal(0.0000001);
        BigDecimal initial = bd;
        BigDecimal diff;

        do {
            BigDecimal sDivX = bd.divide(initial, 8, RoundingMode.FLOOR);
            BigDecimal sum = sDivX.add(initial);
            BigDecimal div = sum.divide(TWO, 8, RoundingMode.FLOOR);
            diff = div.subtract(initial).abs();
            diff.setScale(8, RoundingMode.FLOOR);
            initial = div;
        } while (diff.compareTo(error) > 0);
        return initial;

    }
    
    public BigDecimal getCount()
    {
        return new BigDecimal(this.data.size());
    };

}
