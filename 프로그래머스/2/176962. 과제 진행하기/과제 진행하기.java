import java.util.*;

class Solution {
    PriorityQueue<Pjt> pq = new PriorityQueue<>(new Comparator<Pjt>() {
        @Override
        public int compare(Pjt o1, Pjt o2) {
            if (o1.start == o2.start) {
                return o2.stopTime - o1.stopTime;
            }
            return o1.start - o2.start;
        }
    });
    PriorityQueue<Pjt> stoppedPq = new PriorityQueue<>(new Comparator<Pjt>() {
        @Override
        public int compare(Pjt o1, Pjt o2) {
            return o2.stopTime - o1.stopTime;
        }
    });
    
    public String[] solution(String[][] plans) {
        String[] answer = {};
        ArrayList<String> answerList = new ArrayList<>();

        for (int i = 0; i < plans.length; i++) {
            String name = plans[i][0];
            int start = timeToInt(plans[i][1]);
            int end = Integer.parseInt(plans[i][2]) + start;
            int stopTime = 2134567890;

            pq.add(new Pjt(name, start, end, stopTime));
        }

        Pjt progress = pq.poll();
        while (!pq.isEmpty()) {
            Pjt now = pq.peek();

            if(progress.end > now.start) {
                int start = now.end;
                int end = progress.end - now.start + now.end;
                int stopTime = now.start;
                Pjt stopped = new Pjt(progress.name, start, end, stopTime);
                stoppedPq.add(stopped);
                progress = now;
                pq.poll();
            } else if (progress.end < now.start) {
                answerList.add(progress.name);

                if (!stoppedPq.isEmpty()) {
                    Pjt stopped = stoppedPq.poll();

                    int start = progress.end;
                    int end = stopped.end - stopped.start + start;
                    int stopTime = stopped.stopTime;

                    Pjt newPjt = new Pjt(stopped.name, start, end, stopTime);
                    progress = newPjt;
                } else {
                    progress = now;
                    pq.poll();
                }
            } else {
                answerList.add(progress.name);
                progress = now;
                pq.poll();
            }
        }

        answerList.add(progress.name);

        while (!stoppedPq.isEmpty()) {
            answerList.add(stoppedPq.poll().name);
        }

        answer = new String[answerList.size()];
        for (int i = 0; i < answerList.size(); i++) {
            answer[i] = answerList.get(i);
            // System.out.println(answer[i]);
        }

        return answer;
    }
    
    private int timeToInt(String s) {
        int ret = 0;

        String[] time = s.split(":");
        ret += Integer.parseInt(time[0]) * 60;
        ret += Integer.parseInt(time[1]);
        return ret;
    }

    class Pjt {
        String name;
        int start;
        int end;
        int stopTime;

        public Pjt(String name, int start, int end, int stopTime) {
            this.name = name;
            this.start = start;
            this.end = end;
            this.stopTime = stopTime;
        }
    }
}