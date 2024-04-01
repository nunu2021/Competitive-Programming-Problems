import happybase as hb

# DON'T CHANGE THE PRINT FORMAT, WHICH IS THE OUTPUT
# OR YOU WON'T RECEIVE POINTS FROM THE GRADER
connection = hb.Connection('localhost')
connection.open()
table_name = "powers"
table= connection.table(table_name)

all_rows=table.scan()

for row_key, data in all_rows:
    color = data[b'custom:color'].decode()
    name = data[b'professional:name'].decode()
    power = data[b'personal:power'].decode()
    
    all_rows_inner=table.scan()
    for inner_row_key, inner_data in all_rows_inner:

        inner_color = inner_data[b'custom:color'].decode()
        inner_name = inner_data[b'professional:name'].decode()
        inner_power = inner_data[b'personal:power'].decode()
        if inner_name != name and color == inner_color:
            print('{}, {}, {}, {}, {}'.format(name, power, inner_name, inner_power, color))
connection.close()