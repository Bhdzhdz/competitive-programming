use std::io::{BufRead, BufWriter, stdin, stdout, Write};
use std::str;
 
/// Reads white-space separated tokens one at a time.
pub struct Scanner<R> {
    reader: R,
    buffer: Vec<String>,
}
 
fn solve() {
    let mut scanner = Scanner::new(stdin().lock());
    let output = &mut BufWriter::new(stdout());
 
    let mut n: i64 = scanner.next();
 
    loop {
        write!(output, "{} ", n).unwrap();
 
        if n == 1 {
            break
        }
 
        n = if n % 2 == 0 {
            n / 2
        } else {
            n * 3 + 1
        }
    }
 
    write!(output, "\n").unwrap();
}
 
fn main() {
    let mut _t: i32 = 1;
    
    // {
    //     let mut scanner = Scanner::new(stdin().lock());
    //     _t = scanner.next();
    // }
 
    while _t > 0 {
        _t -= 1;
        solve();
    }
}

 
impl<R: BufRead> Scanner<R> {
    pub fn new(reader: R) -> Self {
        Self {
            reader,
            buffer: vec![],
        }
    }
 
    /// Use "turbofish" syntax token::<T>() to select data type of next token.
    ///
    /// # Panics
    ///
    /// Panics if there's an I/O error or if the token cannot be parsed as T.
    pub fn next<T: str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok().expect("Failed parse");
            }            
            let mut input = String::new();
            self.reader.read_line(&mut input).expect("Failed read");
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }
 
    /// Read a line of input into a vector of tokens.
    pub fn next_line<T: str::FromStr>(&mut self) -> Vec<T> {
        if self.buffer.is_empty() {
            let mut input = String::new();
            self.reader.read_line(&mut input).expect("Failed read");
            input.split_whitespace().map(|x| x.parse().ok().expect("Failed parse")).collect()
        } else {
            self.buffer.drain(..).map(|x| x.parse().ok().expect("Failed parse")).rev().collect()
        }
    }
}