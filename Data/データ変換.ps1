# Excel
$directory = Convert-Path .
$directory += "\"
$filename = $directory + "data.xlsx"
$item = Get-Item $filename
$excel = New-Object -ComObject Excel.Application
$book = $excel.Workbooks.Open($item.FullName)

# monsters 読み込み
$sheet = $book.Worksheets("monster")

$range = $sheet.Range("monsters")

$num_rows = $range.Rows.Count
$num_columns = $range.Columns.Count
$csv = ""
for($i = 1; $i -le $num_rows; $i++){
    for($j = 1; $j -le $num_columns; $j++){
        $csv += $range[$j][$i].Text
        if($j -ne $num_columns){
            $csv += ","
        }
    }
    $csv += "`n"
}

$json = $csv | ConvertFrom-Csv | ConvertTo-Json
$json_monster = """monsters"" : " + $json

# textを読み込み
$sheet = $book.Worksheets("text")
$range = $sheet.Range("text")

$num_rows = $range.Rows.Count
$num_columns = $range.Columns.Count
$csv = ""
for($i = 1; $i -le $num_rows; $i++){
    for($j = 1; $j -le $num_columns; $j++){
        $csv += $range[$j][$i].Text
        if($j -ne $num_columns){
            $csv += ","
        }
    }
    $csv += "`n"
}

$json = $csv | ConvertFrom-Csv | ConvertTo-Json
$json_text = """texts"" : " + $json

# playerを読み込み
$sheet = $book.Worksheets("player")
$range = $sheet.Range("player")

$num_rows = $range.Rows.Count
$num_columns = $range.Columns.Count
$csv = ""
for($i = 1; $i -le $num_rows; $i++){
    for($j = 1; $j -le $num_columns; $j++){
        $csv += $range[$j][$i].Text
        if($j -ne $num_columns){
            $csv += ","
        }
    }
    $csv += "`n"
}

$json = $csv | ConvertFrom-Csv | ConvertTo-Json
$json_player = """player"" : " + $json

$json_output = "{" + $json_monster + "," + $json_text + "," + $json_player + "}"
$output = $directory + "data.json"
$json_output | Out-File -Encoding utf8 $output