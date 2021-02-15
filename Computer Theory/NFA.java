import java.util.*;

public class NFA {

    public static final int SZ = 10;

    public static void main(String[] args) {
        // transition.get(s).get(c) is the Set of states with arrows from s
        // labelled c. Beware: If no arrows exist, null is returned
        Map<String, Map<String, Set<String>>> transition = new HashMap<>();
        
        // Grab first line as NFA's input
        Scanner in = new Scanner(System.in);
        String input = in.nextLine();
        
        // Read states and insert blank entry for each in transitions
        String tmp = in.nextLine();  // Should be "#states"
        tmp = in.nextLine();         // Should be first state
        while ( ! tmp.equals("#initial")) {
            transition.put(tmp, new HashMap<String, Set<String>>());
            tmp = in.nextLine();
        }
        
        // Get the start state
        String startState = in.nextLine();

        // Build set of accepting states
        Set<String> acceptStates = new HashSet<>();
        tmp = in.nextLine();   // Should be "#accepting"
        tmp = in.nextLine();   // Should be first accepting state
        while ( ! tmp.equals("#alphabet")) {
            acceptStates.add(tmp);
            tmp = in.nextLine();
        }

        // Skip over alphabet to "#transitions", add transitions to end-of-input
        while ( ! tmp.equals("#transitions"))
            tmp = in.nextLine();
        while (in.hasNextLine()) {
            tmp = in.nextLine();
            int colon = tmp.indexOf(":");
            int greater = tmp.indexOf(">");
            String src = tmp.substring(0,colon);
            String label = tmp.substring(colon+1,greater);
            String dst = tmp.substring(greater+1);
            if ( ! transition.get(src).containsKey(label))
                transition.get(src).put(label, new HashSet<String>());
            transition.get(src).get(label).add(dst);
        }
       
        // Call simulator and report result
        if (recognizes(transition, startState, acceptStates, input))
            System.out.println("'" + input + "' is accepted");
        else
            System.out.println("'" + input + "' is rejected");
    }
    
    private static boolean recognizes(
                Map<String, Map<String, Set<String>>> transition,
                String startState,
                Set<String> acceptStates,
                String input)
    {
        Set<String> curStates = new HashSet<>(); // Holds states NFA could be in
        curStates.add(startState);               // Initially only the start state
        
        //Needs work
        for(char c : input.toCharArray())
        {
            String ch = String.valueOf(c);
            Set<String> nextCurStates = new HashSet<>();
            for(String state : curStates)
            {
                if(transition.get(state).get(ch) == null)
                {
                    continue;
                }
                nextCurStates.addAll(transition.get(state).get(ch));
            }
            curStates = nextCurStates;
        }
        
        //Done
        curStates.retainAll(acceptStates);
        if(curStates.isEmpty())
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}
