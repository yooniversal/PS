public String[] runCircuitBreaker(String[][] requests, int failureThreshold, int openDuration) {
    List<String> results = new ArrayList<>();

    int failCount = 0;
    long openUntilTime = -1;
    
    for (int i=0; i<requests.length; i++) {
        long timestamp = Long.parseLong(requests[i][0]);
        String outcome = requests[i][1];

        boolean halfOpenState = false;

        if (timestamp <= openUntilTime) {
            // OPEN
            results.add("REJECTED:OPEN");
            continue;
        } else if (openUntilTime != -1) {
            // HALF-OPEN
            halfOpenState = true;
        }

        if (outcome.equals("SUCCESS")) {
            // SUCCESS
            failCount = 0;
            openUntilTime = -1;
            results.add("ALLOWED:CLOSED");
        } else {
            // FAILURE
            failCount++;

            if (halfOpenState || failCount >= failureThreshold) {
                // TRIGGER OPEN
                failCount = 0;
                openUntilTime = timestamp + openDuration - 1;
                results.add("ALLOWED:OPEN");
            } else {
                // MAINTAIN ALLOWED
                results.add("ALLOWED:CLOSED");
            }
        }
    }

    String[] ret = new String[results.size()];
    for (int i=0; i<ret.length; i++) {
        ret[i] = results.get(i);
    }

    return ret;
}