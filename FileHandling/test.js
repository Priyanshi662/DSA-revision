const loan = {
    date: new Date("2023-10-01"),
    amount: 1000, // Replace with the actual loan amount
    frequency: "MONTH" // Replace with the actual loan frequency
};

function findFirstPaymentDate(transactions, loan) {
    const { date: loanDate, amount: loanAmount, frequency: loanFrequency } = loan;
  
    // Sort transactions by start date in ascending order
    transactions.sort((a, b) => a.startDate - b.startDate);
  
    let availableBalance = 0;
  
    for (const transaction of transactions) {
      const { startDate, amount, frequency, type } = transaction;
  
      if (type === "DEBIT") {
        if (startDate > loanDate) {
          // Calculate the time difference between the transaction date and the loan date
          const timeDiff = startDate - loanDate;
          const daysDiff = timeDiff / (1000 * 3600 * 24);
  
          // Determine the number of loan frequency periods elapsed
          let periodsElapsed = 0;
          if (loanFrequency === "MONTH") {
            periodsElapsed = Math.floor(daysDiff / 30);
          } else if (loanFrequency === "QUARTER") {
            periodsElapsed = Math.floor(daysDiff / 90);
          } else if (loanFrequency === "YEAR") {
            periodsElapsed = Math.floor(daysDiff / 365);
          }
  
          // Deduct the loan amount for each period elapsed
          availableBalance -= loanAmount * periodsElapsed;
        }
  
        // Deduct the transaction amount from the available balance
        availableBalance -= amount;
      } else if (type === "CREDIT") {
        // Add the transaction amount to the available balance
        availableBalance += amount;
      }
  
      if (availableBalance >= loanAmount) {
        return new Date(loanDate.getTime() + (loanFrequency === "MONTH" ? 30 : loanFrequency === "QUARTER" ? 90 : 365) * 24 * 60 * 60 * 1000);
      }
    }
  
    return "Not Possible";
  }