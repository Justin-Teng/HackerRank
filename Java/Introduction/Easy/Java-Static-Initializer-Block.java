    static Scanner in = new Scanner(System.in);
    static int B;
    static int H;
    static boolean flag = true;
    
    static {
        B = in.nextInt();
        in.nextLine();
        H = in.nextInt();
        in.close();
        if (B <= 0 || H <= 0) {
            System.out.println("java.lang.Exception: Breadth and height must be positive");
            flag = false;
        }
    }
