BEGIN   {
    print "EMPLOYEES DETAILS"
    total_pay = 0
    count = 0
}
{
    salary_per_day = $2
    days_worked = $3
    total_salary = salary_per_day * days_worked

    if(salary_per_day > 6000 && days_worked > 4){
        print $1, total_salary
        total_pay += total_salary
        count += 1
    }
}
END {
    print "no of employees are " count
    print " total pays = " total_pay
    if(count >0){
        print "average pay = ", total_pay / count
    }
    else{
        print "average pay = 0"
    }
}