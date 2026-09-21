import java.util.List;

abstract class Base {
    protected String address;
    static int flag;
    private List<Base> lb;

    public abstract int work();
}


class Jump extends Base implements Job {
    private int counter;

    public Jump(String s) {
        address = s;
    }

    public int work() {
        return 0;
    }

    public void setJob() {
        return;
    }
}


class Rope implements Deliver {
    private int id;
    public Base myJump;

    public void setJob() {
        return;
    }

    public int doDelivery() {
        return -1;
    }
}


public interface Job {
    public void setJob();
}


public interface Deliver extends Job {
    public int doDelivery();
}
