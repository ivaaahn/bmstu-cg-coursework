
Color get_color(X: Color, Y: Color, hit: HitData);

Ray get_left_ray();
Ray get_right_ray()


Color X;
Color Y;

class HitData:
    exitst: bool
    ray: Ray
    mat: Material
    hit: Point
    norm: Vector
    left_color: Color
    depth: char

depth = 0;

stack = [];

curr_color = BGColor(); // == right_color

while(true):
    while curr.exist:
        new_depth = stack ? stack.peek().depth + 1 : 0

        stack.push(curr, new_depth)
        stack.push(curr, new_depth)
        curr = getLeft(curr)

        curr.exist = new_depth == 2 ? false : intersect()

    if stack.size() == 0:
        return curr_color

    curr = stack.pop();


    if stack.size() > 0 and stack.peek() == curr: // значит поднялись по левой ветке
    stack.peek().left_info = curr_color;
    curr_color = BGColor();
    curr = getRight(curr)
    curr.exist = intersect()

else:
    curr_color = getColor(curr.left_color, curr_color)
    curr.exist = false;


*/