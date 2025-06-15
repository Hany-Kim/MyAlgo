import java.util.*;

class Solution {
    int defaultTime;
    int defaultFee;
    int unitTime;
    int unitFee;
    Map<String, String> prkingInfoMap = new HashMap<>();
    Map<String, Integer> timSumMap = new HashMap<>();
    Map<Integer, Integer> feeMap = new TreeMap<>();
    
    public int[] solution(int[] fees, String[] records) {
        int[] answer = {};

        setFees(fees);

        for (int i = 0; i < records.length; i++) {
            String[] record = records[i].split(" ");
            String nowTime = record[0];
            String nowCarNum = record[1];
            String nowType = record[2];

            if (nowType.equals("IN")) {
                prkingInfoMap.put(nowCarNum, nowTime);
            } else {
                String inTime = prkingInfoMap.get(nowCarNum);
                prkingInfoMap.remove(nowCarNum);

                String outTime = nowTime;

                String[] inHourMin = inTime.split(":");
                String[] outHourMin = outTime.split(":");
                int inHour = Integer.parseInt(inHourMin[0]);
                int inMin = Integer.parseInt(inHourMin[1]);
                int outHour = Integer.parseInt(outHourMin[0]);
                int outMin = Integer.parseInt(outHourMin[1]);

                int diff = 0;
                if (inMin > outMin) {
                    outHour -= 1;
                    diff += (outHour - inHour) * 60;
                    diff += outMin + 60 - inMin;
                } else {
                    diff += (outHour - inHour) * 60;
                    diff += outMin - inMin;
                }

                if (timSumMap.containsKey(nowCarNum)) {
                    int sum = timSumMap.get(nowCarNum) + diff;
                    timSumMap.remove(nowCarNum);
                    timSumMap.put(nowCarNum, sum);
                } else {
                    timSumMap.put(nowCarNum, diff);
                }
            }
        }

        if (!prkingInfoMap.isEmpty()) {
            for (String key : prkingInfoMap.keySet()) {
                String inTime = prkingInfoMap.get(key);
                String outTime = "23:59";

                String[] inHourMin = inTime.split(":");
                String[] outHourMin = outTime.split(":");
                int inHour = Integer.parseInt(inHourMin[0]);
                int inMin = Integer.parseInt(inHourMin[1]);
                int outHour = Integer.parseInt(outHourMin[0]);
                int outMin = Integer.parseInt(outHourMin[1]);

                int diff = 0;
                if(inMin > outMin) {
                    outHour -= 1;
                    diff += (outHour - inHour) * 60;
                    diff += outMin + 60 - inMin;
                } else {
                    diff += (outHour - inHour) * 60;
                    diff += outMin - inMin;
                }

                if (timSumMap.containsKey(key)) {
                    int sum = timSumMap.get(key) + diff;
                    timSumMap.remove(key);
                    timSumMap.put(key, sum);
                } else {
                    timSumMap.put(key, diff);
                }
            }
        }

        for (String key : timSumMap.keySet()) {
            int sumTime = timSumMap.get(key);
            int fee = 0;

            fee += defaultFee;
            if (sumTime > defaultTime) {
                int unitTimeCnt = (int) Math.ceil(((double) sumTime - (double) defaultTime) / (double) unitTime);
                fee += unitTimeCnt * unitFee;
            }

            feeMap.put(Integer.parseInt(key), fee);
        }

        answer = feeMap.values().stream().mapToInt(Integer::intValue).toArray();

        return answer;
    }
    
    private void setFees(int[] fees) {
        defaultTime = fees[0];
        defaultFee = fees[1];
        unitTime = fees[2];
        unitFee = fees[3];
    }
}