public class Quiz {

    private static Queue<String> toks;

    private static boolean isEmpty() { return toks.isEmpty(); }
    private static String  next()    { return toks.element(); }
    private static void match(String tok) {
        if (isEmpty() || !next().equals(tok))
            throw new IllegalStateException("Error on match(" + tok + ")");
        toks.remove();
    }
    
    /* Parses a prefix of toks and returns reference to resulting parse tree. */
    /* Throws IllegalStateException if an error occurs.                      */
    private static DefaultMutableTreeNode parseS() {
        DefaultMutableTreeNode rval = new DefaultMutableTreeNode("S");
        
        if(isEmpty())
        {
            throw new IllegalStateException("Empty: ");
        }
        else if(next().equals("+") || next().equals("*"))
        {
            String tok = next();
            match(tok);
            rval.add(new DefaultMutableTreeNode(tok));
            rval.add(parseS());
            rval.add(parseS());
        }
        else if(next().equals("a"))
        {
            String tok = next();
            match(tok);
            rval.add(new DefaultMutableTreeNode(tok));
        }
        else
        {
            throw new IllegalStateException("Unexpected: " + next());
        }
        
        return rval;
    }

    /* Converts "input" to a Queue of non-whitespace length-1 token Strings.  */
    /* Parses all of toks and returns reference to resulting parse tree.      */
    /* Throws IllegalStateException if an error occurs.                       */
    public static DefaultMutableTreeNode parseToTree(String input) {
        input = input.replaceAll("\\s","");  // Deletes all whitespace
        toks = new LinkedList<String>();
        for (char ch : input.toCharArray())
            toks.add(Character.toString(ch));
        DefaultMutableTreeNode result = parseS();
        if ( ! isEmpty() )
            throw new IllegalStateException("Parse error");
        else
            return result;
    }

    public static String toString(TreeNode t) {
        if (t.isLeaf())
            if (t.toString().equals(""))
                return "λ";
            else
                return t.toString();
        else {
            String result = "(" + t.toString();
            for (int i=0; i<t.getChildCount(); i++)
                result += " " + toString(t.getChildAt(i));
            return result + ")";
        }
    }

    // This is here for quick tests if you are working in an IDE.
    // It is ignored by my tests
    public static void main(String[] args) {
        System.out.println(toString(parseToTree("+*aa*aa")));
    }

}
