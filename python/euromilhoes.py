import random

class euro:
    def __init__(self):
        self.nums = [0,0,0,0,0]
        self.stars = [0,0]
        self.generated_nums = [0,0,0,0,0]
        self.generated_stars = [0,0]
    
    def check_values(self, max, values):
        for index, x in enumerate(values):
            if x > str(max) or x < "1":
                if max==50:
                    self.nums[index] = input(f"invalid num {self.nums[index]}, change: ")
                elif max==10:
                    self.stars[index] = input(f"invalid star {self.stars[index]}, change: ")
                return False
        return True

    def check_repeated_values(self, flag):
        if flag==0:
            set_values = set(self.nums)
            size = len(self.nums)
        elif flag==1:
            set_values = set(self.stars)
            size = len(self.stars)

        size_set = len(set_values)
        if size != size_set:
            for x in range(size_set, size):
                new_value = input("repeated number, change: ")
                set_values.add(new_value)
            if flag==0:
                self.nums = list(set_values)
            elif flag==1:
                self.stars = list(set_values)
        return True

    def read_values(self):
        result = False
        result2 = False 
        in_nums = input("Enter the numbers :")
        self.nums = in_nums.split(",")

        while result==False or result2==False:
            result = self.check_repeated_values(0)
            result2 = self.check_values(50, self.nums)
        print(self.nums)

        result = False
        result2 = False 
        in_stars = input("Enter the stars :")
        self.stars = in_stars.split(",")

        while result==False or result2==False:
            result = self.check_repeated_values(1)
            result2 = self.check_values(9, self.stars)
        print(self.stars)

    def genarate_random(self):
        self.generated_nums = random.sample(range(1, 50), 5)
        self.generated_stars = random.sample(range(1, 10), 2)     

        self.generated_nums = [str(x) for x in self.generated_nums]
        self.generated_stars = [str(x) for x in self.generated_stars]

        print(self.generated_nums)
        print(list(self.generated_stars))

    def compare(self):
        equal_nums = list(set(self.nums).intersection(set(self.generated_nums)))
        equal_stars = list(set(self.stars).intersection(set(self.generated_stars)))
        print(f"numbers equals {len(equal_nums)}, equal stars {len(equal_stars)}")

if __name__ == "__main__":
    my_euro = euro()
    my_euro.read_values()
    my_euro.genarate_random()
    my_euro.compare()