BEGIN {
    print "NAME SUB-1 SUB-2 SUB-3 SUB-4 SUB-5 SUB-6 STATUS"
    print "_____________________________________________________________"
}

{
    name = $1
    sub1 = $2
    sub2 = $3
    sub3 = $4
    sub4 = $5
    sub5 = $6
    sub6 = $7

    status = "PASS"

    # Check if any subject is less than 45
    if (sub1 < 45 || sub2 < 45 || sub3 < 45 || sub4 < 45 || sub5 < 45 || sub6 < 45) {
        status = "FAIL"
    }

    print name, sub1, sub2, sub3, sub4, sub5, sub6, status
}
