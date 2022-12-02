pub fn part_one(input: &str) -> Option<u32> {
    let mut best_total: u32 = 0;

    let mut current_total: u32 = 0;
    for line in input.lines() {
        if line == "" {
            if current_total > best_total {
                best_total = current_total;
            }
            current_total = 0;
            continue;
        }
        current_total += line.parse::<u32>().unwrap();
    }
    if current_total > best_total {
        best_total = current_total;
    }

    Some(best_total)
}

pub fn part_two(input: &str) -> Option<u32> {
    let mut best_totals: Vec<u32> = vec![0; 3];

    let mut current_total: u32 = 0;
    for line in input.lines() {
        if line == "" {
            for (pos, total) in best_totals.iter().enumerate() {
                if current_total > *total {
                    best_totals[pos..].rotate_right(1);
                    best_totals[pos] = current_total;
                    break;
                }
            }
            current_total = 0;
            continue;
        }
        current_total += line.parse::<u32>().unwrap();
    }
    for (pos, total) in best_totals.iter().enumerate() {
        if current_total > *total {
            best_totals[pos..].rotate_right(1);
            best_totals[pos] = current_total;
            break;
        }
    }

    Some(best_totals.iter().sum())
}

fn main() {
    let input = &advent_of_code::read_file("inputs", 1);
    advent_of_code::solve!(1, part_one, input);
    advent_of_code::solve!(2, part_two, input);
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_part_one() {
        let input = advent_of_code::read_file("examples", 1);
        assert_eq!(part_one(&input), Some(24000));
    }

    #[test]
    fn test_part_two() {
        let input = advent_of_code::read_file("examples", 1);
        assert_eq!(part_two(&input), Some(45000));
    }
}
