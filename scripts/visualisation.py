import os
import json
import matplotlib.pyplot as plt


def save_plot(fig, filename):
    base_name = os.path.basename(filename).replace('.instance.json', '')
    output_dir = 'visualisations'
    os.makedirs(output_dir, exist_ok=True)
    output_file = os.path.join(output_dir, f'{base_name}.png')

    fig.savefig(output_file, bbox_inches='tight')
    plt.close(fig)

    print(f"Saved plot to {output_file}")


def plot_from_json_file(filename, saved=False):
    with open(filename, 'r') as f:
        json_data = json.load(f)

    points_x = json_data["points_x"]
    points_y = json_data["points_y"]
    region_boundary = json_data["region_boundary"]
    instance_uid = json_data["instance_uid"]

    fig, ax = plt.subplots(figsize=(8, 8))

    for i in range(len(region_boundary)):
        start_index = region_boundary[i]
        end_index = region_boundary[(i + 1) % len(region_boundary)]
        ax.plot([points_x[start_index], points_x[end_index]],
                [points_y[start_index], points_y[end_index]],
                'b-')

    ax.plot(points_x, points_y, 'ko')

    padding_x = (max(points_x) - min(points_x)) * 0.05
    padding_y = (max(points_y) - min(points_y)) * 0.05

    ax.set_xlim(min(points_x) - padding_x, max(points_x) + padding_x)
    ax.set_ylim(min(points_y) - padding_y, max(points_y) + padding_y)

    ax.set_title(instance_uid)

    plt.subplots_adjust(left=0.1, right=0.9, top=0.9, bottom=0.1)

    plt.show()

    if saved:
        save_plot(fig, filename)


if __name__ == "__main__":
    file_name = 'data/example_instances_rev1/cgshop2025_examples_ortho_20_b099d1fe.instance.json'

    plot_from_json_file(file_name, saved=True)
